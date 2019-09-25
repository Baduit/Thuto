#include <iostream>
#include <cassert>
#include <string>

#include "split.hpp"

void basic()
{
    std::vector<std::string_view> expected_strings = {"Salut", "comment", "ça", "va", "Très", "bien", "et", "toi"};

    auto result = Thuto::split("Salut comment ça va? Très bien, et toi?", {" ", "?", ","});

    assert(result.size() == expected_strings.size());
    assert(result == expected_strings);
}

void multiple_stacked_delim()
{
    std::vector<std::string_view> expected_strings = {"Salut", "comment", "ça", "va", "Très", "bien", "et", "toi"};

    auto result = Thuto::split("Salut comment ça va?? Très   bien,, et toi?", {" ", "?", ","});

    assert(result.size() == expected_strings.size());
    assert(result == expected_strings);
}

void multiple_caractere_delim()
{
    std::vector<std::string_view> expected_strings = {"Salut", "comment", "ça", "va", "Très", "bien", "et", "toi"};

    auto result = Thuto::split("Salut  comment  ça  va  ??  Très  bien,,,  et  toi??", {"  ", "??", ",,,"});

    assert(result.size() == expected_strings.size());
    assert(result == expected_strings);
}

void delim_at_begin_and_end()
{
    std::vector<std::string_view> expected_strings = {"Salut", "comment", "ça", "va", "Très", "bien", "et", "toi"};

    auto result = Thuto::split(" Salut comment ça va? Très bien, et toi?  ", {" ", "?", ","});

    assert(result.size() == expected_strings.size());
    assert(result == expected_strings);
}

void template_parameter_output_container()
{
    // TODO
}

void copied_delimer()
{
    std::vector<std::string_view> delims = {" ", "?", ","};
    std::vector<std::string_view> expected_strings = {"Salut", "comment", "ça", "va", "Très", "bien", "et", "toi"};

    auto result = Thuto::split("Salut comment ça va? Très bien, et toi?", delims);

    assert(result.size() == expected_strings.size());
    assert(result == expected_strings);
}

void owning_string_delimiter()
{
    using namespace std::string_literals;
    std::vector<std::string_view> expected_strings = {"Salut", "comment", "ça", "va", "Très", "bien", "et", "toi"};

    auto result = Thuto::split("Salut comment ça va? Très bien, et toi?", {" "s, "?"s, ","s});

    assert(result.size() == expected_strings.size());
    assert(result == expected_strings);
}

void moved_delimiter()
{
    std::vector<std::string_view> delims = {" ", "?", ","};
    std::vector<std::string_view> expected_strings = {"Salut", "comment", "ça", "va", "Très", "bien", "et", "toi"};

    auto result = Thuto::split("Salut comment ça va? Très bien, et toi?", std::move(delims));

    assert(result.size() == expected_strings.size());
    assert(result == expected_strings);
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