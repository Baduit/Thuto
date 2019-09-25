#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <optional>
#include <initializer_list>

#include "StringViewAlgoDetails.hpp"

namespace Thuto
{

namespace
{

using namespace std::string_view_literals;

template < template <typename> typename InputContainer, typename StrView, template <typename> typename OutputContainer>
OutputContainer<std::string_view>	split_impl(std::string_view str, InputContainer<StrView>&& delims)
{
	if (str.empty())
		return {};

	std::sort(delims.begin(), delims.end(), [](std::string_view a, std::string_view b) { return a > b; });

	OutputContainer<std::string_view> result;
	std::back_insert_iterator inserter = std::back_inserter(result);

	std::size_t i = 0;
	std::size_t word_begin = 0;
	while (i < str.size())
	{
		auto d = Details::get_delim(str.substr(i), delims);
		if (d)
		{
			auto word = str.substr(word_begin, i - word_begin);
			if (!word.empty())
				inserter = word;
			i += d->size();
			word_begin = i;
		}
		else
		{
			++i;
		}
	}

	if (word_begin != i)
		inserter = str.substr(word_begin, i - word_begin);
	
	return result;
}

}

// copy
template <template <typename> typename InputContainer = std::vector, typename StrView = std::string_view, template <typename> typename OutputContainer = std::vector>
OutputContainer<std::string_view>	split(std::string_view str, const InputContainer<StrView>& delims)
{
	return split_impl<InputContainer, StrView, OutputContainer>(str, InputContainer<StrView>(delims.begin(), delims.end()));
}

// move/copy ellision
template <template <typename> typename InputContainer = std::vector, typename StrView = std::string_view, template <typename> typename OutputContainer = std::vector>
OutputContainer<std::string_view>	split(std::string_view str, InputContainer<StrView>&& delims)
{
	return split_impl<InputContainer, StrView, OutputContainer>(str, std::move(delims));
}

}