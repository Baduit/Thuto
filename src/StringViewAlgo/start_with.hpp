#pragma once

#include <string_view>

namespace Thuto
{

inline bool	start_with(std::string_view str, std::string_view substr)
{
	if (str.size() < substr.size())
		return false;
	
	for (std::size_t i = 0; i < substr.size(); ++i)
	{
		if (str[i] != substr[i])
			return false;
	}

	return true;
}

}
