#include <cassert>
#include <thread>

#include "Timer.hpp"
#include "timer_helper.hpp"

using namespace std::chrono_literals;

// Tests

void basic_usage()
{

	Thuto::SimpleClock sc;
	std::this_thread::sleep_for(10ms);
	assert(almost_equal(nanoToMilli(sc.getTimeNanoCount()), 10));

	sc.reset();
	assert(almost_equal(sc.getDuractionAs<std::chrono::milliseconds>().count(), 0));
}

void copy()
{
	{
		Thuto::SimpleClock sc1;
		std::this_thread::sleep_for(20ms);

		Thuto::SimpleClock sc2(sc1);
		assert(almost_equal(sc1.getDuractionAs<std::chrono::milliseconds>().count(), sc2.getDuractionAs<std::chrono::milliseconds>().count()));
	}

	{
		Thuto::SimpleClock sc1;
		std::this_thread::sleep_for(20ms);

		Thuto::SimpleClock sc2;
		std::this_thread::sleep_for(20ms);
		sc2 = sc1;
		assert(almost_equal(sc1.getDuractionAs<std::chrono::milliseconds>().count(), sc2.getDuractionAs<std::chrono::milliseconds>().count()));
	}
	
}

int main()
{
	basic_usage();
	copy();
}