#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <algorithm>
#include <string_view>
#include <vector>
#include <list>

#include <thuto/utils/OptionalIt.hpp>

TEST_CASE("basic")
{
	std::vector v = { 1, 2, 3, 4, 5};
	{
		auto it = thuto::OptionalIt(std::find(v.begin(), v.end(), 3), v.end());
		REQUIRE(bool(it));
		CHECK(*it == 3);
	}
	{
		auto it = thuto::OptionalIt(std::find(v.begin(), v.end(), 8), v.end());
		CHECK(!bool(it));
	}
}

TEST_CASE("test_with_objects")
{
	std::list<std::string_view> v = { "1", "2", "33", "4", "5"};
	{
		auto it = thuto::OptionalIt(std::find(v.begin(), v.end(), "33"), v.end());
		REQUIRE(bool(it));
		CHECK(*it == "33");
		CHECK(it->length() == 2);
	}
	{
		auto it = thuto::OptionalIt(std::find(v.begin(), v.end(), "8"), v.end());
		CHECK(!bool(it));
	}
}