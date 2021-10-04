#pragma once

#include <string_view>
#include <cstdio>

#include <thuto/io/CFileHandler.hpp>

namespace thuto
{

// Windows doc https://docs.microsoft.com/en-us/previous-versions/96ayss4b(v=vs.140)
// Linux doc https://linux.die.net/man/3/popen

enum class PopenMode
{
	READ, // "r"
	WRITE // "w"
	// I didn't add platform specific ones
};

CFileHandler popen(std::string_view command, PopenMode mode);

// Command and mode must be null terminated
CFileHandler popen(std::string_view command, std::string_view mode);

constexpr std::string_view popen_mode_to_str(PopenMode mode);

template <PopenMode mode>
auto popen(std::string_view command)
{
	if constexpr (mode == PopenMode::READ)
		return ReadOnlyCFileHandler(popen(command, mode));
	else // if constexpr (mode == PopenMode::READ)
		return WriteOnlyCFileHandler(popen(command, mode));
}

} // namespace thuto