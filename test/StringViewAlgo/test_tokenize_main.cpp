#include <iostream>
#include <cassert>
#include <string>

#include "tokenize.hpp"

using namespace std::string_view_literals;

void basic()
{
    std::vector<Thuto::Token> expected_tokens =
        {
            Thuto::Token("Salut", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("comment", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("ça", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("va", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("Très", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("bien", Thuto::Token::Type::WORD),
            Thuto::Token(",", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("et", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("toi", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER)
        };

    auto result = Thuto::tokenize("Salut comment ça va? Très bien, et toi?", {" ", "?", ","});


    assert(result.size() == expected_tokens.size());
    assert(result == expected_tokens);
}

void multiple_stacked_delim()
{
        std::vector<Thuto::Token> expected_tokens =
        {
            Thuto::Token("Salut", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("comment", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("ça", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("va", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("Très", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("bien", Thuto::Token::Type::WORD),
            Thuto::Token(",", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(",", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("et", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("toi", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER)
        };

    auto result = Thuto::tokenize("Salut comment ça va?? Très   bien,, et toi?", {" ", "?", ","});

    assert(result.size() == expected_tokens.size());
    assert(result == expected_tokens);
}

void multiple_caractere_delim()
{
    std::vector<Thuto::Token> expected_tokens =
        {
            Thuto::Token("Salut", Thuto::Token::Type::WORD),
            Thuto::Token("  ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("comment", Thuto::Token::Type::WORD),
            Thuto::Token("  ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("ça", Thuto::Token::Type::WORD),
            Thuto::Token("  ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("va", Thuto::Token::Type::WORD),
            Thuto::Token("  ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("??", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("  ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("Très", Thuto::Token::Type::WORD),
            Thuto::Token("  ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("bien", Thuto::Token::Type::WORD),
            Thuto::Token(",,,", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("  ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("et", Thuto::Token::Type::WORD),
            Thuto::Token("  ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("toi", Thuto::Token::Type::WORD),
            Thuto::Token("??", Thuto::Token::Type::DELIMiTER)
        };

    auto result = Thuto::tokenize("Salut  comment  ça  va  ??  Très  bien,,,  et  toi??", {"  ", "??", ",,,"});

    assert(result.size() == expected_tokens.size());
    assert(result == expected_tokens);
}

void delim_at_begin_and_end()
{
        std::vector<Thuto::Token> expected_tokens =
        {
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("Salut", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("comment", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("ça", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("va", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("Très", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("bien", Thuto::Token::Type::WORD),
            Thuto::Token(",", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("et", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("toi", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER)
        };

    auto result = Thuto::tokenize(" Salut comment ça va? Très bien, et toi?  ", {" ", "?", ","});

    assert(result.size() == expected_tokens.size());
    assert(result == expected_tokens);
}

void template_parameter_output_container()
{
    // TODO
}

void copied_delimer()
{
    std::vector<std::string_view> delims = {" ", "?", ","};
    std::vector<Thuto::Token> expected_tokens =
        {
            Thuto::Token("Salut", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("comment", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("ça", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("va", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("Très", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("bien", Thuto::Token::Type::WORD),
            Thuto::Token(",", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("et", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("toi", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER)
        };

    auto result = Thuto::tokenize("Salut comment ça va? Très bien, et toi?", delims);

    assert(result.size() == expected_tokens.size());
    assert(result == expected_tokens);
}

void owning_string_delimiter()
{
    using namespace std::string_literals;
    std::vector<Thuto::Token> expected_tokens =
        {
            Thuto::Token("Salut", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("comment", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("ça", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("va", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("Très", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("bien", Thuto::Token::Type::WORD),
            Thuto::Token(",", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("et", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("toi", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER)
        };

    auto result = Thuto::tokenize("Salut comment ça va? Très bien, et toi?", {" "s, "?"s, ","s});

    assert(result.size() == expected_tokens.size());
    assert(result == expected_tokens);
}

void moved_delimiter()
{
    std::vector<std::string_view> delims = {" ", "?", ","};
    std::vector<Thuto::Token> expected_tokens =
        {
            Thuto::Token("Salut", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("comment", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("ça", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("va", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("Très", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("bien", Thuto::Token::Type::WORD),
            Thuto::Token(",", Thuto::Token::Type::DELIMiTER),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("et", Thuto::Token::Type::WORD),
            Thuto::Token(" ", Thuto::Token::Type::DELIMiTER),
            Thuto::Token("toi", Thuto::Token::Type::WORD),
            Thuto::Token("?", Thuto::Token::Type::DELIMiTER)
        };

    auto result = Thuto::tokenize("Salut comment ça va? Très bien, et toi?", std::move(delims));

    assert(result.size() == expected_tokens.size());
    assert(result == expected_tokens);
}

int main()
{
    basic();
    multiple_stacked_delim();
    multiple_caractere_delim();
    delim_at_begin_and_end();
    template_parameter_output_container();
    copied_delimer();
    owning_string_delimiter();
    moved_delimiter();
}