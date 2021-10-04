#include <thuto/io/file.hpp>

namespace thuto
{

std::optional<std::string> read_file(const char* filename)
{
	return read_file(std::ifstream(filename));
}

std::optional<std::string> read_file(const std::string& filename)
{
	return read_file(std::ifstream(filename));
}

std::optional<std::string> read_file(const std::filesystem::path& filename)
{
	return read_file(std::ifstream(filename));
}

std::optional<std::string> read_file(std::ifstream stream)
{
	if (!stream)
		return {};
	
	std::string contents;
    stream.seekg(0, std::ios::end);
    contents.resize(static_cast<std::size_t>(stream.tellg()));
    stream.seekg(0, std::ios::beg);
    stream.read(&contents[0], static_cast<std::streamsize>(contents.size()));
    return contents;
}

} // namespace thuto