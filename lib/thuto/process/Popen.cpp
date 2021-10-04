#include <thuto/process/Popen.hpp>

namespace thuto
{

CFileHandler popen(std::string_view command, PopenMode mode)
{
	return popen(command, popen_mode_to_str(mode));
}

CFileHandler popen(std::string_view command, std::string_view mode)
{
	#if defined(_WIN32)
		return ::_popen(command.data(), mode.data());
	#else
		return ::popen(command.data(), mode.data());
	#endif
}

constexpr std::string_view popen_mode_to_str(PopenMode mode)
{
	if (mode == PopenMode::READ)
		return "r";
	else // (mode == PopenMode::WRITE)
		return "w";
}

} // namespace thuto