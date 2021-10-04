#pragma once

#include <iterator>
#include <vector>
#include <mutex>
#include <algorithm>
#include <ranges>

namespace thuto
{

// Can have several writer but only one reader
template <typename Event, typename Container = std::vector<Event>>
class EventQueue
{
	public:
		void push(const Event& t)
		{
			std::lock_guard guard(_mutex);
			std::back_inserter(_collection) = t;
		}

		void push(Event&& t)
		{
			std::lock_guard guard(_mutex);
			std::back_inserter(_collection) = std::forward<Event>(t);
		}

		template <std::ranges::input_range Range>
		void push(const Range& r)
		{
			std::lock_guard guard(_mutex);
			std::copy(std::ranges::cbegin(r), std::ranges::cend(r), std::back_inserter(_collection));
		}

		template <std::ranges::input_range Range>
		void push(Range&& r)
		{
			std::lock_guard guard(_mutex);
			std::ranges::move(r, std::back_inserter(_collection));
		}

		[[nodiscard]] bool empty() const
		{
			std::lock_guard guard(_mutex);
			return _collection.empty();
		}

		[[nodiscard]] auto size() const
		{
			std::lock_guard guard(_mutex);
			return _collection.size();
		}

		void clear()
		{
			std::lock_guard guard(_mutex);
			return _collection.clear();
		}

		[[nodiscard]] Container get_all()
		{
			Container result;
			{
				std::lock_guard guard(_mutex);
				result.swap(_collection);
			}
			return result;
			
		}

	private:
		Container _collection;
		mutable std::mutex _mutex;
};

} // namespace thuto