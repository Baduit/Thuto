#include <thuto/utils/Env.hpp>

#include <cstdlib>

namespace thuto
{

std::optional<std::string_view> get_env(const char* var_name)
{
	const char* res = std::getenv(var_name);
	if (res)
		return res;
	else
		return {};
}	

std::optional<std::string_view> get_env(const std::string& var_name)
{
	return get_env(var_name.c_str());
}

} // namespace thuto