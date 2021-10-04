#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <concepts>

#include <thuto/utils/ArrayUtils.hpp>



static_assert(thuto::StdArray<std::array<int, 3>>);
static_assert(!thuto::StdArray<int[3]>);
static_assert(!thuto::StdArray<int>);

static_assert(thuto::BoundedArray<std::array<int, 3>>);
static_assert(thuto::BoundedArray<int[3]>);
static_assert(!thuto::BoundedArray<int>);

static_assert(std::same_as<thuto::ArrayValueTypeT<std::array<int, 3>>, int>);
static_assert(std::same_as<thuto::ArrayValueTypeT<int[5]>, int>);

static_assert(thuto::BoundedArraysWithSameValueType<std::array<int, 3>, std::array<int, 5>>);
static_assert(!thuto::BoundedArraysWithSameValueType<std::array<char, 3>, std::array<int, 5>>);
static_assert(thuto::BoundedArraysWithSameValueType<int[3], int[5]>);
static_assert(!thuto::BoundedArraysWithSameValueType<long[3], int[5]>);
static_assert(thuto::BoundedArraysWithSameValueType<std::array<int, 3>, int[5]>);
static_assert(!thuto::BoundedArraysWithSameValueType<long[3], std::array<int, 5>>);

constexpr std::array<int, 3> std_array = { 1, 2, 3 };
constexpr int raw_array[2] = { 1, 2 };
constexpr auto res = thuto::concat_array(std_array, raw_array);
static_assert(res == std::array<int, 5>{ 1, 2, 3, 1, 2 });

// I think this test is useless since the code is validated with static_assert
TEST_CASE("basic")
{
	std::array<int, 3> std_array = { 1, 2, 3 };
	int raw_array[2] = { 1, 2 };
	auto res = thuto::concat_array(std_array, raw_array);
	CHECK(res == std::array<int, 5>{ 1, 2, 3, 1, 2 });
}
