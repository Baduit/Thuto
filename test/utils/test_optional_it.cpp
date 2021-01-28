#include <algorithm>
#include <string_view>
#include <vector>
#include <list>

#include <boost/ut.hpp>
#include <Thuto/utils/OptionalIt.hpp>

using namespace boost::ut;

int main()
{
	"basic"_test =
		[]()
		{
			std::vector v = { 1, 2, 3, 4, 5};
			{
				auto it = thuto::OptionalIt(std::find(v.begin(), v.end(), 3), v.end());
				expect(bool(it));
				expect(*it == 3);
			}
			{
				auto it = thuto::OptionalIt(std::find(v.begin(), v.end(), 8), v.end());
				expect(!bool(it));
			}
		};

	"test_with_objects"_test =
		[]()
		{
			std::list<std::string_view> v = { "1", "2", "33", "4", "5"};
			{
				auto it = thuto::OptionalIt(std::find(v.begin(), v.end(), "33"), v.end());
				expect(bool(it));
				expect(*it == "33");
				expect(it->length() == 2);
			}
			{
				auto it = thuto::OptionalIt(std::find(v.begin(), v.end(), "8"), v.end());
				expect(!bool(it));
			}
		};
}