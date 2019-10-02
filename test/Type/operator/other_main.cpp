#include <cassert>
#include <string_view>
#include <iostream>

#include "HasOperator.hpp"

struct Dummy
{
    auto operator()(std::string_view str) { return str.size(); }
};

void test_operator_function_call_with()
{
    assert((Thuto::has_operator_function_call_with<Dummy, int>() == false));
    assert((Thuto::has_operator_function_call_with<Dummy, std::string_view>() == true));
    assert((Thuto::has_operator_function_call_with<Dummy, std::string>() == true));
    assert((Thuto::has_operator_function_call_with<Dummy, const char*>() == true));
    assert((Thuto::has_operator_function_call_with<Dummy, Dummy>() == false));
}

int main()
{
    test_operator_function_call_with();
}