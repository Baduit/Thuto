#include <algorithm>
#include <string_view>
#include <vector>
#include <list>
#include <deque>
#include <thread>

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

			{
				auto events = e.get_all();
				expect(e.empty()) << "Event queue is now empty";
				expect((events.size() == 3) >> fatal) << "There a 3 retrieved events";
				expect(events[0] == 5) << "First event";
				expect(events[1] == 3) << "Second event";
				expect(events[2] == 3) << "Third";
			}

			{
				const std::vector v = {1, 2, 3};
				e.push(v);
				auto events = e.get_all();
				expect(e.empty());
				expect((events.size() == 3) >> fatal);
				expect(events[0] == 1);
				expect(events[1] == 2);
				expect(events[2] == 3);
			}

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

			{
				auto events = e.get_all();
				expect(e.empty()) << "Event queue is now empty";
				expect((events.size() == 3) >> fatal);
				expect(events[0] == 5);
				expect(events[1] == 3);
				expect(events[2] == 3);
			}

			{
				const std::array<int, 3> v = {1, 2, 3};
				e.push(v);
				auto events = e.get_all();
				expect(e.empty()) << "Event queue is now empty";
				expect((events.size() == 3) >> fatal);
				expect(events[0] == 1);
				expect(events[1] == 2);
				expect(events[2] == 3);
			}
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

			{
				auto events = e.get_all();
				expect(e.empty()) << "Event queue is now empty";
				expect((events.size() == 3) >> fatal);

				auto it = events.begin();
				expect(*it == 5);

				++it;
				expect(*it == 3);

				++it;
				expect(*it == 3);
			}

			{
				auto v = {1, 2, 3};
				e.push(v);
				auto events = e.get_all();
				expect(e.empty()) << "Event queue is now empty";
				expect((events.size() == 3) >> fatal);

				auto it = events.begin();
				expect(*it == 1);

				++it;
				expect(*it == 2);

				++it;
				expect(*it == 3);
			}
		};

	"non_copyable"_test =
		[]()
		{
			// A thread is not copyable
			thuto::concurrency::EventQueue<std::thread> event_queue;

			{
				std::vector<std::thread> data;
				data.push_back({});
				data.push_back({});
				event_queue.push(data);
				expect(event_queue.size() == 2) << "Two element after copy insertion";
				event_queue.clear();
			}

			{
				std::vector<std::thread> data;
				data.push_back({});
				data.push_back({});
				event_queue.push(std::move(data));

				std::cout << "TOTO IS == " << event_queue.size() << std::endl;
				expect(event_queue.size() == 2) << "Two element after range insertion";
			}
		};
}