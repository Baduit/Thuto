#include <iostream>
#include <cassert>
#include <string_view>

#include "Expected.hpp"

using namespace std::string_view_literals;
using namespace std::string_literals;

enum struct A { NO };
enum struct B { NO };
enum struct C { NO };

void test_wrapper()
{
	Thuto::GenericValueType<int> value(5);
	int a = 5;
	int& a_ref = a;
	Thuto::GenericValueType<int&> ref(a_ref);
}

void	test_expected_value()
{
	Thuto::Expected<int, A> value_wrapped(5);

	Thuto::Expected<int, A, std::string_view> yo("THIS IS AN ERROR"sv);
    assert(yo.hold_alternative<std::string_view>());
	assert(!yo.hold_alternative<int>());
	assert(yo != std::string_view("efgegegeg"));
	assert(yo == std::string_view("THIS IS AN ERROR"));
	assert(yo.getOr(5) == 5);

	Thuto::Expected<std::string, A>	one(""s);
	Thuto::Expected<std::string, A>	two(std::move(one));
	Thuto::Expected<std::string, A>	three(Thuto::Expected<std::string, A>(""s));

	Thuto::Expected<std::string, A>		little("a"s);
	assert(little && little.hold_alternative<std::string>() && *little == "a");

	Thuto::Expected<std::string, A, B>		bigger(std::move(little));
	assert(bigger && *bigger == "a");

 	Thuto::Expected<std::string, A, B, C>	even_bigger(Thuto::Expected<std::string, A, B>("b"));
	assert(even_bigger && *even_bigger == "b");

	Thuto::Expected<double, A, B>	big_err { Thuto::Expected<double, A>(A::NO) };
	assert(!big_err && big_err.index() == 1 && big_err == A::NO);

	Thuto::Expected<double, A, B, C>	big_err_bis { Thuto::Expected<double, A, B>(B::NO) };
	assert(!big_err_bis && big_err_bis.index() == 2 && big_err_bis == B::NO);
}

void 	test_expected_ref()
{
	int i = 5;
	int& i_ref = i;
	Thuto::Expected<int&, A> expect_i_or_a = i_ref;
	Thuto::Expected<int&, A> expect_i_or_a_bis = std::move(expect_i_or_a);
	Thuto::Expected<int&, A, std::string> expect_i_or_a_string = std::move(expect_i_or_a_bis);

	assert(expect_i_or_a);
	assert(expect_i_or_a_string.hold_alternative<int&>());
	assert(*expect_i_or_a_string == 5);
	assert(expect_i_or_a_string.get_by_index<0>() == 5);
	assert(expect_i_or_a_string.get_by_type<int&>() == 5);
	assert(expect_i_or_a_string == 5);
	//assert(expect_i_or_a_string != ""s);

	Thuto::Expected<const int&, B> expect_i_or_b = B{};
	assert(!expect_i_or_b);
	assert(expect_i_or_b.get_by_index<1>() == B{});
	assert(expect_i_or_b.get_by_type<B>() == B{});
	assert(expect_i_or_b.getOr(5) == 5);
}

int	main()
{
	std::cout << "Hello World!" << std::endl;

	test_wrapper();
	test_expected_value();
	test_expected_ref();

	std::cout << "Bye World" << std::endl;
}