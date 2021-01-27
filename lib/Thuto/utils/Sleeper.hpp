#pragma once

#include <mutex>
#include <condition_variable>

#include <Thuto/utils/Clock.hpp>

namespace thuto
{

/*
** Make a thread sleep, same as std::this_thread::sleep_for but cancelable.
*/
class Sleeper
{
	public:
		Sleeper() = default;

		Sleeper(const Sleeper&) = delete;
		Sleeper& operator=(const Sleeper&) = delete;

		Sleeper(Sleeper&&) = delete;
		Sleeper& operator=(Sleeper&&) = delete;

		virtual ~Sleeper()
		{
			cancel_all();
		}

		template<typename D>
		Sleeper(const D& duration)
		{
			sleep(duration);
		}

		template<typename D>
		void	operator()(const D& duration)
		{
			sleep(duration);
		}

		template<typename D>
		void	sleep(const D& duration)
		{
			std::unique_lock lock(_mutex);
			_cv.wait_for(lock, duration);
		}

		// Use it if you want to awake only one thread sleeping
		void	cancel_one()
		{
			_cv.notify_one();
		}

		// Use it if you cant to awake all the sleeping threads (one or more)
		void	cancel_all()
		{
			_cv.notify_all();
		}

	private:
		std::mutex				_mutex;
		std::condition_variable	_cv;
};

} // namespace thuto