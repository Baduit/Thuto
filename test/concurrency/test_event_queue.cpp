#include <algorithm>
#include <string_view>
#include <vector>
#include <list>
#include <deque>

#include <boost/ut.hpp>
#include <Thuto/concurrency/EventQueue.hpp>

using namespace boost::ut;

int main()
{
	"basic"_test =
		[]()
		{
			thuto::concurrency::EventQueue<int> e;
			e.push(5);
			const int a = 3;
			e.push(a);
			const int& b = a;
			e.push(b);
			auto events = e.get_all();
			expect(e.empty());
			expect((events.size() == 3) >> fatal);
			expect(events[0] == 5);
			expect(events[1] == 3);
			expect(events[2] == 3);
		};

	"deque"_test =
		[]()
		{
			thuto::concurrency::EventQueue<int, std::deque<int>> e;
			e.push(5);
			const int a = 3;
			e.push(a);
			const int& b = a;
			e.push(b);
			auto events = e.get_all();
			expect(e.empty());
			expect((events.size() == 3) >> fatal);
			expect(events[0] == 5);
			expect(events[1] == 3);
			expect(events[2] == 3);
		};

	"list"_test =
		[]()
		{
			thuto::concurrency::EventQueue<int, std::list<int>> e;
			e.push(5);
			const int a = 3;
			e.push(a);
			const int& b = a;
			e.push(b);
			auto events = e.get_all();
			expect(e.empty());
			expect((events.size() == 3) >> fatal);

			auto it = events.begin();
			expect(*it == 5);

			++it;
			expect(*it == 3);

			++it;
			expect(*it == 3);
		};
}