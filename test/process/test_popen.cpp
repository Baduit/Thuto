#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <array>

#include <thuto/process/Popen.hpp>


TEST_CASE("read")
{
	std::string echo_arg = "trop_lol_mdr";
	std::string cmd = "echo " + echo_arg;
	std::string expected = echo_arg + "\n";
	auto handle = thuto::popen<thuto::PopenMode::READ>(cmd);

	std::array<char, 25> buffer;
	buffer.fill('\0');

	std::size_t nb_read = handle.read(buffer);
	CHECK(nb_read == expected.size());
	CHECK(buffer.data() == expected);
}