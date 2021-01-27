#pragma once

namespace thuto
{

/* template <typename T>
class EventQueue
{
	public:
		void push(const T& t)
		{
			std::lock_guard guard(_mutex);
			_collection.push_back(t);
		}

		void push(T&& t)
		{
			std::lock_guard guard(_mutex);
			_collection.push_back(std::move(t));
		}

		bool _is_empty() const
		{
			std::lock_guard guard(_mutex);
			return _collection.empty();
		}

		std::optional<T>	pop()
		{
			std::lock_guard guard(_mutex);
			if (!_collection.empty())
			{
				T t = _collection.front();
				_collection.erase(_collection.begin());
				return t;
			}
			else
			{
				return {};
			}
			
		}

		// empty_collection must not me modified during the process !!!
		void swap_with_empty_collection(std::vector<T>& empty_collection)
		{
			std::lock_guard guard(_mutex);
			empty_collection.swap(_collection);
			
		}

	private:
		std::vector<T>			_collection;
		mutable std::mutex		_mutex;
}; */

} // namespace thuto