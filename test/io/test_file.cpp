#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <array>

#include <thuto/io/file.hpp>

void create_file_with_stuff_in_it(const std::string& filename, const std::string& content)
{
	std::ofstream out(filename);
	out << content;
}

TEST_CASE("basic read file")
{
	std::string filename = "rgrgegerg";
	std::string content = "Hey you, lol, maybe, fromage !!!";
	create_file_with_stuff_in_it(filename, content);

	auto output = thuto::read_file(filename);
	REQUIRE(output.has_value());
	CHECK(*output == content);
}