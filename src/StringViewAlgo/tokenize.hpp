#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <optional>
#include <initializer_list>

#include "StringViewAlgoDetails.hpp"

namespace Thuto
{

struct Token
{
	enum class Type
	{
		DELIMiTER,
		WORD
	}; 

	Token(std::string_view str, Type t): value(str), type(t) {}
	Token(const Token&) = default;
	Token& operator=(const Token&) = default;
	Token(Token&&) = default;
	Token& operator=(Token&&) = default;

	std::string_view	operator*() const { return value; };

	friend bool operator==(const Token& a, const Token& b) { return (a.type == b.type) && (a.value == b.value); }
	friend bool operator!=(const Token& a, const Token& b) { return !(a == b); }

	std::string_view 	value;
	Type				type;
};

namespace
{

using namespace std::string_view_literals;

template < template <typename> typename InputContainer = std::vector, typename StrView = std::string_view, template <typename> typename OutputContainer = std::vector>
OutputContainer<Token>	tokenize_impl(std::string_view str, InputContainer<StrView>&& delims)
{
	if (str.empty())
		return {};
	
	std::sort(delims.begin(), delims.end(), [](std::string_view a, std::string_view b) { return a > b; });

	OutputContainer<Token> result;
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
				inserter = Token(word,  Token::Type::WORD);
			i += d->size();
			word_begin = i;
			inserter = Token(*d, Token::Type::DELIMiTER);
		}
		else
		{
			++i;
		}
	}

	if (word_begin != i)
		inserter = Token(str.substr(word_begin, i - word_begin), Token::Type::WORD);
	
	return result;
}

}

// copy
template <template <typename> typename InputContainer = std::vector, typename StrView = std::string_view, template <typename> typename OutputContainer = std::vector>
OutputContainer<Token>	tokenize(std::string_view str, const InputContainer<StrView>& delims)
{
	return tokenize_impl(str, std::vector<StrView>(delims.begin(), delims.end()));
}

// move/copy ellision
template <template <typename> typename InputContainer = std::vector, typename StrView = std::string_view, template <typename> typename OutputContainer = std::vector>
OutputContainer<Token>	tokenize(std::string_view str, InputContainer<StrView>&& delims)
{
	return tokenize_impl(str, std::move(delims));
}

}