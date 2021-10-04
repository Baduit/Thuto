#pragma once

#include <atomic>

#include <thuto/utils/Sleeper.hpp>

namespace thuto
{

/*
** Execute an action at the end of the choosed duration in a loop in the current thread.
** For the moment it can't be paused.
*/
class Poller
{
	public:
		enum class LoopStatus
		{
			CONTINUE,
			STOP
		};

	public:
		Poller() = default;

		Poller(const Poller&) = delete;
		Poller& operator=(const Poller&) = delete;

		Poller(Poller&&) = delete;
		Poller& operator=(Poller&&) = delete;

		template<typename D, typename Cb>
		Poller(const D& duration, Cb&& cb)
		{
			start(duration, std::forward<Cb>(cb));
		}

		virtual ~Poller()
		{
			stop();
		}

		template<typename D, typename Cb>
		void	operator()(const D& duration, Cb&& cb)
		{
			start(duration, std::forward<Cb>(cb));
		}

		template<typename D, typename Cb>
		void	start(const D& duration, Cb&& cb)
		{
			while (!_stop)
			{
				_sleeper(duration);
				if (!_stop)
				{
					using CbReturnType = std::invoke_result_t<Cb>;
					if constexpr (std::is_same_v<CbReturnType, LoopStatus>)
					{
						if (cb() == LoopStatus::STOP)
							stop();
					}
					else
					{
						cb();
					}
				}
			}
		}

		void	stop()
		{
			_stop = true;
			_sleeper.cancel_all();
		}

	private:
		std::atomic<bool>	_stop { false };
		Sleeper				_sleeper;
};


} // namespace thuto