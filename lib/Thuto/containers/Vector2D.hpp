#pragma once

namespace thuto
{

/* template <typename T>
class Vector2D
{
	public:
		Vector2D() = default;
		Vector2D(std::size_t x, std::size_t y):_size({x, y}),  _container(x * y) {}
		Vector2D(Size2D size):_size(size),  _container(size.x * size.y) {}

		Vector2D(const Vector2D&) = default;
		Vector2D& operator=(const Vector2D&) = default;
		Vector2D(Vector2D&&) = default;
		Vector2D& operator=(Vector2D&&) = default;

		~Vector2D() = default;

		void	resize(std::size_t x, std::size_t y)
		{
			_size = {x, y};
			_container.resize(x * y);
		}

		T&			operator[](Position2D pos) { return _container[pos.x + pos.y * _size.x]; }
		const T&	operator[](Position2D pos) const { return _container[pos.x + pos.y * _size.x]; }

		T&			operator()(std::size_t x, std::size_t y) { return _container[x +y * _size.x]; }
		const T&	operator()(std::size_t x, std::size_t y) const { return _container[x +y * _size.x]; }

		const Size2D&	get_size() const { return _size; }

		// be carefull to not resize the undelying container, it could easily cause some bugs
		std::vector<T>&			get_container() noexcept { return _container; }
		const std::vector<T>&	get_container() const noexcept { return _container; }

		bool is_in_map(const Position2D& pos) const
		{
			return
				pos.x != NO_POS &&
				pos.x < _size.x &&
				pos.y != NO_POS &&
				pos.y < _size.y;
		}


	private:
		Size2D			_size;
		std::vector<T>	_container;
}; */


} // namespace thuto