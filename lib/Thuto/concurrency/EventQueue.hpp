#pragma once

#include <iterator>
#include <vector>
#include <mutex>

namespace thuto::concurrency
{

// Can have several writer but only one reader
template <typename Value>
class EventQueue
{
	public:
		void push(const Value& t)
		{
			std::lock_guard guard(_mutex);
			std::back_inserter(_collection) = t;
		}

		void push(Value&& t)
		{
			std::lock_guard guard(_mutex);
			std::back_inserter(_collection) = std::forward<Value>(t);
		}

		[[nodiscard]] bool empty() const
		{
			std::lock_guard guard(_mutex);
			return _collection.empty();
		}

		void clear()
		{
			std::lock_guard guard(_mutex);
			return _collection.clear();
		}

		[[nodiscard]] std::vector<Value> get_all()
		{
			std::vector<Value> result;
			{
				std::lock_guard guard(_mutex);
				result.swap(_collection);
			}
			return result;
			
		}

	private:
		std::vector<Value>		_collection;
		mutable std::mutex		_mutex;
};

} // namespace thuto