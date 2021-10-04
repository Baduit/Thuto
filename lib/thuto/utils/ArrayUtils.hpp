#pragma once

#include <type_traits>
#include <array>
#include <algorithm>

namespace thuto
{

template <typename T>
struct IsStdArray : std::false_type {};

template <typename T, std::size_t N>
struct IsStdArray<std::array<T, N>> : std::true_type {};

template <typename T>
concept StdArray = std::is_base_of_v<std::true_type, IsStdArray<T>>;

template <typename T>
concept RawBoundedArray = std::is_bounded_array_v<T>;

template <typename T>
concept BoundedArray = RawBoundedArray<T> || StdArray<T>;

template <BoundedArray T>
struct ArrayValueType
{
	using ValueType = std::remove_reference_t<decltype(std::declval<T>()[0])>;
};

template <BoundedArray T>
using ArrayValueTypeT = typename ArrayValueType<T>::ValueType;

template <typename T, typename U>
concept BoundedArraysWithSameValueType =
	BoundedArray<T> &&
	BoundedArray<U> &&
	std::same_as<ArrayValueTypeT<T>, ArrayValueTypeT<U>>;

// I could have just made 4 overload to handle
// - std_array + stdarray
// - raw_array + std_array
// - std_array + raw_array
// - raw_array + raw_array
// It would have probably been simpler, and it the compile time would be better
// But the error message is way simpler with this implementation, and I find the interface more clear
// Note I wanted to use concepts and I have just one function and not 4 with overloads
// And this is my library I'm making for fun so I'm doing as I wish
// Also on my pet project I see low value to do something I already have done a lot of time instead of new stuff I almost never used
// Keep in mind that I use this project for learning purpose

template <BoundedArray T>
constexpr std::size_t bounded_array_size()
{
	if constexpr(StdArray<T>)
		return std::tuple_size_v<T>;
	else
		return std::extent_v<T>;
}

template <BoundedArray T, BoundedArraysWithSameValueType<T> U>
constexpr auto concat_array(const T& t, const U& u)
{
	using ResultArrayType = ArrayValueTypeT<T>;
	constexpr std::size_t result_array_size = bounded_array_size<T>() + bounded_array_size<U>();

	std::array<ResultArrayType, result_array_size> result_array;
	std::ranges::copy(t, result_array.begin());
	std::ranges::copy(u, result_array.begin() + bounded_array_size<T>());
	return result_array;
}

}  // namespace thuto