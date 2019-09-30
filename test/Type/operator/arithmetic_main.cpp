#include <cassert>
#include <iostream>

#include "HasOperator.hpp"

struct Nothing {};

struct WithOperator
{
    WithOperator& operator=(int) { return *this; }

    int operator++() { return 5; } // ++i so before
    int operator++(int) { return 5; } // i++ so after

    int operator+(const WithOperator&) { return 5; }
};

void test_has_operator()
{
    assert(Thuto::has_operator_increment_before<WithOperator>());
    assert(Thuto::has_operator_increment_after<WithOperator>());
    assert(Thuto::has_operators_increment<WithOperator>());

    assert((Thuto::has_operator_addition_with<WithOperator, WithOperator>()));

    assert((Thuto::has_operator_assigment_with<WithOperator, int>));

    assert(!Thuto::has_operator_increment_before<Nothing>());
}

struct a
{
    virtual ~a();
};

int main()
{
    test_has_operator();
}