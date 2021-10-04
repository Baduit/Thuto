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
		SimpleClock();

		SimpleClock(const SimpleClock&) = default;
		SimpleClock& operator=(const SimpleClock&) = default;

		SimpleClock(SimpleClock&&) = default;
		SimpleClock& operator=(SimpleClock&&) = default;

		virtual ~SimpleClock() = default;

		void reset();
		
		[[nodiscard]] Duration get_time_duration();

		template<typename T>
		[[nodiscard]] auto get_duration_as() { return std::chrono::duration_cast<T>(get_time_duration()); }

		[[nodiscard]] int64_t get_time_nano_count();

	private:
		std::chrono::system_clock::time_point _first;
};

/*
** You can have the duration between now and the last reset of the clock. 
** It can be paused.
** Default status at construction: started.
*/
class AdvancedClock
{
	public:
		AdvancedClock();

		AdvancedClock(const AdvancedClock&) = default;
		AdvancedClock& operator=(const AdvancedClock&) = default;

		AdvancedClock(AdvancedClock&&) = default;
		AdvancedClock& operator=(AdvancedClock&&) = default;

		virtual ~AdvancedClock() = default;

		void reset();
		
		[[nodiscard]] auto get_time_duration();

		template<typename T>
		[[nodiscard]] auto get_duration_as()
		{
			return _run_timer.get_duration_as<T>() - get_total_pause_time_as<T>();
		}

		[[nodiscard]] int64_t get_time_nano_count();
		void pause();
		void start();
		[[nodiscard]] Duration get_total_pause_time();

		template<typename T>
		[[nodiscard]] auto  get_total_pause_time_as()
		{
			return std::chrono::duration_cast<T>(get_total_pause_time());
		}


		[[nodiscard]] int64_t get_total_pause_time_nano_count();

	private:
		SimpleClock _run_timer;
		std::optional<SimpleClock> _pause_timer;
		Duration _paused_time;
};

} // namespace thuto