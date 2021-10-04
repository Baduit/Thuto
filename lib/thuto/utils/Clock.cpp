#include <thuto/utils/Clock.hpp>

namespace thuto
{
/*
** SimpleClock
*/
SimpleClock::SimpleClock()
{
	reset();
}

void SimpleClock::reset()
{
	_first = std::chrono::system_clock::now();
}

Duration SimpleClock::get_time_duration()
{
	return std::chrono::system_clock::now() - _first;
}

int64_t SimpleClock::get_time_nano_count()
{
	return get_duration_as<std::chrono::nanoseconds>().count();
}

/*
** AdvancedClock
*/
AdvancedClock::AdvancedClock()
{
	reset();
}

void AdvancedClock::reset()
{
	_run_timer.reset();
	_pause_timer.reset();
	_paused_time = {};
}

auto AdvancedClock::get_time_duration()
{
	return _run_timer.get_time_duration() - get_total_pause_time();
}

int64_t AdvancedClock::get_time_nano_count()
{
	return _run_timer.get_time_nano_count() - get_total_pause_time_nano_count();
}

void AdvancedClock::pause()
{
	if (!_pause_timer.has_value())
		_pause_timer.emplace();
}

void AdvancedClock::start()
{
	if (_pause_timer.has_value())
	{
		_paused_time += _pause_timer->get_time_duration();
		_pause_timer.reset();
	}
}

Duration AdvancedClock::get_total_pause_time()
{
	return (_pause_timer.has_value()) ? _paused_time + _pause_timer->get_time_duration() : _paused_time;
}



int64_t AdvancedClock::get_total_pause_time_nano_count()
{
	return get_total_pause_time_as<std::chrono::nanoseconds>().count();
}


} // namespace thuto