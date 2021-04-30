#pragma once

#include <string_view>
#include <cstdlib>

namespace thuto
{

// var_name must be null terminated
// this is also the reason it doesn't use std::string_view
std::string_view get_env(const char* var_name);

} // namespace thuto