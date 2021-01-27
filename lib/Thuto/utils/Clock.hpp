#pragma once

#include <chrono>
#include <optional>
#include <cstdint>

namespace thuto
{

using Duration = decltype(std::chrono::system_clock::now() - std::chrono::system_clock::now());

/*
** You can have the duration between now and the last reset of the clock. 
** It can't be paused.
*/
class SimpleClock
{
	public:
		SimpleClock() { reset(); };

		SimpleClock(const SimpleClock&) = default;
		SimpleClock& operator=(const SimpleClock&) = default;

		SimpleClock(SimpleClock&&) = default;
		SimpleClock& operator=(SimpleClock&&) = default;

		virtual ~SimpleClock() = default;

		void		reset() { _first = std::chrono::system_clock::now(); }
		
		Duration	get_time_duration() { return std::chrono::system_clock::now() - _first; }

		template<typename T>
		auto		get_duration_as() { return std::chrono::duration_cast<T>(get_time_duration()); }

		int64_t		get_time_nano_count() { return get_duration_as<std::chrono::nanoseconds>().count(); }

	private:
		std::chrono::system_clock::time_point	_first;
};

/*
** You can have the duration between now and the last reset of the clock. 
** It can be paused.
** Default status at construction: started.
*/
class AdvancedClock
{
	public:
		AdvancedClock() { reset(); }

		AdvancedClock(const AdvancedClock&) = default;
		AdvancedClock& operator=(const AdvancedClock&) = default;

		AdvancedClock(AdvancedClock&&) = default;
		AdvancedClock& operator=(AdvancedClock&&) = default;

		virtual ~AdvancedClock() = default;

		void		reset()
		{
			_run_timer.reset();
			_pause_timer.reset();
			_paused_time = {};
		}
		
		auto		get_time_duration()
		{
			return _run_timer.get_time_duration() - get_total_pause_time();
		}

		template<typename T>
		auto		get_duration_as()
		{
			return _run_timer.get_duration_as<T>() - get_total_pause_time_as<T>();
		}

		int64_t		get_time_nano_count()
		{
			return _run_timer.get_time_nano_count() - get_total_pause_time_nano_count();
		}

		void		pause()
		{
			if (!_pause_timer.has_value())
				_pause_timer.emplace();
		}

		void		start()
		{
			if (_pause_timer.has_value())
			{
				_paused_time += _pause_timer->get_time_duration();
				_pause_timer.reset();
			}
		}

		Duration	get_total_pause_time()
		{
			return (_pause_timer.has_value()) ? _paused_time + _pause_timer->get_time_duration() : _paused_time;
		}

		template<typename T>
		auto 	get_total_pause_time_as() { return std::chrono::duration_cast<T>(get_total_pause_time()); }


		int64_t	get_total_pause_time_nano_count() { return get_total_pause_time_as<std::chrono::nanoseconds>().count(); }

	private:
		SimpleClock						_run_timer;
		std::optional<SimpleClock>		_pause_timer;
		Duration						_paused_time;
};

} // namespace thuto