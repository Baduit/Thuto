#pragma once

namespace thuto
{

/* template <HasId T>
class Hand
{
	public:
		Hand(std::size_t max_size):
			_max_size(max_size)
		{}

		std::size_t get_max_size() const { return _max_size; }
		void set_max_size(std::size_t max_size) { _max_size = max_size; }

		bool is_full() const { return _container.size() == _max_size; }
		bool is_empty() const { return _container.empty(); }
		bool get_actual_size() const { return _container.size(); }

		bool add(T&& t)
		{
			if (is_full())
				return false;

			_container.push_back(std::move(t));
			return true;
		}

		T	take(int id)
		{
			auto cmp_cb =
				[&](const auto& x)
				{
					return x.get_id() == id;
				};

			auto it = std::find_if(_container.begin(), _container.end(), cmp_cb);
			if (it == _container.end())
				throw std::runtime_error("Object in hand not found");
			
			T result = std::move(*it);
			_container.erase(it);
			return result;
		}


		auto	begin()	{ return _container.begin(); }
		auto	cbegin() const { return _container.cbegin(); }
		auto	end() { return _container.end(); }
		auto	cend() const { return _container.cend(); }

		auto	rbegin()	{ return _container.rbegin(); }
		auto	crbegin() const { return _container.crbegin(); }
		auto	rend() { return _container.rend(); }
		auto	crend() const { return _container.crend(); }
		
	private:
		std::size_t _max_size;
		std::vector<T> _container;
}; */

} // namespace thuto