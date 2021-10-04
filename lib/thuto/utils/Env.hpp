#pragma once

#include <string>
#include <optional>
#include <string_view>

namespace thuto
{

// var_name must be null terminated
// this is also the reason it doesn't use std::string_view
std::optional<std::string_view> get_env(const char* var_name);

std::optional<std::string_view> get_env(const std::string& var_name);

} // namespace thuto