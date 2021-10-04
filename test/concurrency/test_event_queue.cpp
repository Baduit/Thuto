#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <array>
#include <algorithm>
#include <string_view>
#include <vector>
#include <list>
#include <deque>
#include <thread>

#include <thuto/concurrency/EventQueue.hpp>

TEST_CASE("basic")
{
	thuto::EventQueue<int> e;
	e.push(5);
	const int a = 3;
	e.push(a);
	const int& b = a;
	e.push(b);

	{
		auto events = e.get_all();
		CHECK_MESSAGE(e.empty(), "Event queue is now empty");
		REQUIRE_MESSAGE(events.size() == 3, "There a 3 retrieved events");
		CHECK_MESSAGE(events[0] == 5, "First event");
		CHECK_MESSAGE(events[1] == 3, "Second event");
		CHECK_MESSAGE(events[2] == 3, "Third");
	}

	{
		const std::vector v = {1, 2, 3};
		e.push(v);
		auto events = e.get_all();
		CHECK(e.empty());
		REQUIRE(events.size() == 3);
		CHECK(events[0] == 1);
		CHECK(events[1] == 2);
		CHECK(events[2] == 3);
	}

}

TEST_CASE("deque")
{
	thuto::EventQueue<int, std::deque<int>> e;
	e.push(5);
	const int a = 3;
	e.push(a);
	const int& b = a;
	e.push(b);

	{
		auto events = e.get_all();
		CHECK_MESSAGE(e.empty(), "Event queue is now empty");
		REQUIRE(events.size() == 3);
		CHECK(events[0] == 5);
		CHECK(events[1] == 3);
		CHECK(events[2] == 3);
	}

	{
		const std::array<int, 3> v = {1, 2, 3};
		e.push(v);
		auto events = e.get_all();
		CHECK_MESSAGE(e.empty(), "Event queue is now empty");
		REQUIRE(events.size() == 3);
		CHECK(events[0] == 1);
		CHECK(events[1] == 2);
		CHECK(events[2] == 3);
	}
}

TEST_CASE("list")
{
	thuto::EventQueue<int, std::list<int>> e;
	e.push(5);
	const int a = 3;
	e.push(a);
	const int& b = a;
	e.push(b);

	{
		auto events = e.get_all();
		CHECK_MESSAGE(e.empty(), "Event queue is now empty");
		REQUIRE(events.size() == 3);

		auto it = events.begin();
		CHECK(*it == 5);

		++it;
		CHECK(*it == 3);

		++it;
		CHECK(*it == 3);
	}

	{
		auto v = {1, 2, 3};
		e.push(v);
		auto events = e.get_all();
		CHECK_MESSAGE(e.empty(), "Event queue is now empty");
		REQUIRE(events.size() == 3);

		auto it = events.begin();
		CHECK(*it == 1);

		++it;
		CHECK(*it == 2);

		++it;
		CHECK(*it == 3);
	}
}

TEST_CASE("non_copyable")
{
	// A thread is not copyable
	thuto::EventQueue<std::thread> event_queue;

	{
		std::vector<std::thread> data;
		data.push_back({});
		data.push_back({});
		event_queue.push(data);
		CHECK_MESSAGE(event_queue.size() == 2, "Two element after copy insertion");
		event_queue.clear();
	}

	{
		std::vector<std::thread> data;
		data.push_back({});
		data.push_back({});
		event_queue.push(std::move(data));

		std::cout << "TOTO IS == " << event_queue.size() << std::endl;
		CHECK_MESSAGE(event_queue.size() == 2, "Two element after range insertion");
	}
}