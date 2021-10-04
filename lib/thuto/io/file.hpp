#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <optional>

namespace thuto
{

std::optional<std::string> read_file(const char* filename);
std::optional<std::string> read_file(const std::string& filename);
std::optional<std::string> read_file(const std::filesystem::path& filename);
std::optional<std::string> read_file(std::ifstream stream);

} // namespace thuto