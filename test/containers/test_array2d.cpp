#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <thuto/containers/Array2D.hpp>

TEST_CASE("basic")
{
	thuto::Array2D<int, 3, 3> v { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	v.at({0, 0}) = 1;
	v.at({1, 0}) = 2;
	v.at({0, 1}) = 3;

	CHECK_MESSAGE(v.at({0, 0}) == 1, "Fist case");
	CHECK_MESSAGE(v.get_container()[0] == 1, "Fist case");

	CHECK_MESSAGE(v.at({1, 0}) == 2, "2nd case");
	CHECK_MESSAGE(v.get_container()[1] == 2, "2nd case");

	CHECK_MESSAGE(v.at({0, 1}) == 3, "Fist case of 2nd line");
	CHECK_MESSAGE(v.get_container()[3] == 3, "Fist case of 2nd line");


	std::array<int, 9> expected_array =
		{
			1, 2, 0,
			3, 0, 0,
			0, 0, 0
		};

	CHECK_MESSAGE(v.get_container() == expected_array, "Check the container has the right content");

	auto first_line = v.get_line(0);
	REQUIRE(first_line.size() == 3);
	CHECK(first_line[0] == 1);
	CHECK(first_line[1] == 2);
	CHECK(first_line[2] == 0);

	auto second_line = v.get_line(1);
	second_line[1] = 4;
	REQUIRE(second_line.size() == 3);
	CHECK(second_line[0] == 3);
	CHECK(second_line[1] == 4);
	CHECK(second_line[2] == 0);

	const auto& cv = v;
	auto const_second_line = cv.get_line(1);
	REQUIRE(const_second_line.size() == 3);
	CHECK(const_second_line[0] == 3);
	CHECK(const_second_line[1] == 4);
	CHECK(const_second_line[2] == 0);
}