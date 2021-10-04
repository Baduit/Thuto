#pragma once

#include <string_view>

#include <thuto/utils/ArrayUtils.hpp>

namespace thuto
{

// Unresizable string to replace const char[N] and std::string_view for string constants
// If you want a resizable string stack allocated, use std::pmr::string
template <std::size_t Size, typename CharT, typename Traits = std::char_traits<CharT>>
class BasicStaticString
{
	using Buffer = std::array<CharT, Size>;

	public:
		// standard case here to have similar aliased with string and string_view
		using traits_type = Traits;
		using value_type = CharT;
		using pointer = CharT*;
		using const_pointer = const CharT*;
		using reference = CharT&;
		using const_reference = const CharT&;

		using const_iterator = Buffer::const_iterator;
		using iterator = const_iterator; // This string is immutable
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;
		using reverse_iterator = const_reverse_iterator; // Still immutable
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;

	public:
		constexpr std::string_view view() const { return _buffer.data(); }


		constexpr auto begin() { return _buffer.begin(); }
		constexpr auto end() { return _buffer.end(); }

		constexpr auto cbegin() const { return _buffer.cbegin(); }
		constexpr auto cend() const { return _buffer.cend(); }

		constexpr auto rbegin() { return _buffer.rbegin(); }
		constexpr auto rend() { return _buffer.rend(); }

		constexpr auto crbegin() const { return _buffer.crbegin(); }
		constexpr auto crend() const { return _buffer.crend(); }

	private:
		Buffer _buffer;
};

template <std::size_t Size>
using StaticString = BasicStaticString<Size, char>;

template <std::size_t Size>
using WStaticString = BasicStaticString<Size, wchar_t>;

template <std::size_t Size>
using U8StaticString = BasicStaticString<Size, char8_t>;

template <std::size_t Size>
using U16StaticString = BasicStaticString<Size, char16_t>;

template <std::size_t Size>
using U32StaticString = BasicStaticString<Size, char32_t>;

} // namespace thuto