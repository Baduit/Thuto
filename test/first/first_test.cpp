#include <iostream>
#include <utility>

#include <boost/ut.hpp>

using namespace boost::ut;

void first()
{
	expect((true) >> fatal) << "If this test fails, the it stops here.";
}

int main()
{
	"first"_test = first;
}
