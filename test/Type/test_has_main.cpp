#include <iostream>
#include <cassert>

#include "HasMethod.hpp"
#include "HasAttribute.hpp"
#include "HasOperator.hpp"

struct Nothing {};

/*
** HAS_METHOD
*/
struct Sized
{
    std::size_t size()
    {
        return 0;
    }
};

void test_has_method()
{
    assert(Thuto::has_method_size<Sized>());
    assert(!Thuto::has_method_size<Nothing>());
}

/*
** HAS_ATTRIBUTE
*/
struct With_X_Y_Z_Width_Height
{
    int height;
    int width;
    int x;
    int y;
    int z;
};

void test_has_attribute()
{
    assert(Thuto::has_attribute_height<With_X_Y_Z_Width_Height>());
    assert(Thuto::has_attribute_width<With_X_Y_Z_Width_Height>());
    assert(Thuto::has_attribute_x<With_X_Y_Z_Width_Height>());
    assert(Thuto::has_attribute_y<With_X_Y_Z_Width_Height>());
    assert(Thuto::has_attribute_z<With_X_Y_Z_Width_Height>());

    assert(!Thuto::has_attribute_height<Nothing>());
    assert(!Thuto::has_attribute_width<Nothing>());
    assert(!Thuto::has_attribute_x<Nothing>());
    assert(!Thuto::has_attribute_y<Nothing>());
    assert(!Thuto::has_attribute_z<Nothing>());
}

/*
** HAS_OPERATOR
*/
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
    test_has_method();
    test_has_attribute();
    test_has_operator();
}