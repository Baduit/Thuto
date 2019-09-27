#include <iostream>
#include <cassert>

#include "HasMethod.hpp"

struct Sized
{
    std::size_t size()
    {
        return 0;
    }
};

struct NotSized {};

int main()
{
    std::cout << has_size<Sized>() << std::endl;
    std::cout << has_size<NotSized>() << std::endl;
}