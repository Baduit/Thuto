#include <cassert>
#include <iostream>

#include "HasOperator.hpp"

struct Nothing {};

struct WithOperator
{
    int operator++() { return 5; } // ++i so before
    int operator++(int) { return 5; } // i++ so after
};

void test_has_operator()
{
    assert(Thuto::has_operator_increment_before<WithOperator>());
    assert(Thuto::has_operators_increment<WithOperator>());
    assert(!Thuto::has_operator_increment_before<Nothing>());
}

int main()
{
    test_has_operator();
}