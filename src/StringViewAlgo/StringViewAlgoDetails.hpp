#pragma once

#include <string_view>
#include <optional>
#include <vector>

#include "start_with.hpp"

namespace Thuto
{

namespace Details
{

template <template <typename> typename InputContainer = std::vector, typename StrView = std::string_view>
std::optional<std::string_view>	get_delim(std::string_view str, const InputContainer<StrView>& delims)
{
	for (std::string_view d: delims)
	{
		if (start_with(str, d))
			return d;
	}

	return {};
}

}

}