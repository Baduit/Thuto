#include <cassert>
#include <iostream>
#include <thread>

#include "Timer.hpp"
#include "timer_helper.hpp"

using namespace std::chrono_literals;

// Tests

void basic_usage()
{

	Thuto::AdvancedClock ac;
	std::this_thread::sleep_for(10ms);
	assert(almost_equal(nanoToMilli(ac.get_time_nano_count()),static_cast<int64_t>(10)));

	ac.pause();
	std::this_thread::sleep_for(10ms);
	assert(almost_equal(ac.get_duraction_as<std::chrono::milliseconds>().count(), static_cast<int64_t>(10)));

	ac.start();
	std::this_thread::sleep_for(10ms);
	assert(almost_equal(ac.get_duraction_as<std::chrono::milliseconds>().count(), static_cast<int64_t>(20)));

	ac.pause();
	std::this_thread::sleep_for(10ms);
	assert(almost_equal(ac.get_duraction_as<std::chrono::milliseconds>().count(), static_cast<int64_t>(20)));
	ac.start();
	assert(almost_equal(ac.get_duraction_as<std::chrono::milliseconds>().count(), static_cast<int64_t>(20)));
}

void copy()
{
	{
		Thuto::AdvancedClock ac1;
		std::this_thread::sleep_for(20ms);
		ac1.pause();
		std::this_thread::sleep_for(20ms);

		Thuto::AdvancedClock ac2(ac1);
		assert(ac1.get_duraction_as<std::chrono::milliseconds>().count() == ac2.get_duraction_as<std::chrono::milliseconds>().count());
	}

	{
		Thuto::AdvancedClock ac1;
		std::this_thread::sleep_for(20ms);

		Thuto::AdvancedClock ac2;
		ac2.pause();
		std::this_thread::sleep_for(20ms);
		ac2 = ac1;
		assert(ac1.get_duraction_as<std::chrono::milliseconds>().count() == ac2.get_duraction_as<std::chrono::milliseconds>().count());
	}
	
}

int main()
{
	basic_usage();
	copy();
}