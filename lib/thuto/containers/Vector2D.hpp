#pragma once

#include <vector>
#include <span>
#include <ranges>

#include <thuto/containers/ContainerAdapter.hpp>
#include <thuto/utils/Pos2D.hpp>
#include <thuto/utils/Size2D.hpp>
#include <thuto/details/Exception.hpp>

namespace thuto
{

template <typename T>
class Vector2D : public ContainerAdapter<Vector2D<T>, std::vector<T>>
{
	friend ContainerAdapter<Vector2D<T>, std::vector<T>>;

	public:
		constexpr Vector2D() = default;

		constexpr Vector2D(std::size_t x, std::size_t y):
			_size({x, y}),
			_container(x * y)
		{}

		constexpr Vector2D(Size2D size):
			_size(size),
			_container(size.x * size.y)
		{}

		constexpr Vector2D(const Vector2D&) = default;
		constexpr Vector2D& operator=(const Vector2D&) = default;

		constexpr Vector2D(Vector2D&&) = default;
		constexpr Vector2D& operator=(Vector2D&&) = default;

		constexpr std::span<T> get_line(std::size_t line_number)
		{
			auto line_begin = &at(0, line_number);
			auto line_length = _size.x;
			return std::span<T>(line_begin, line_length);
		}

		constexpr std::span<const T> get_line(std::size_t line_number) const
		{
			auto line_begin = &at(0, line_number);
			auto line_length = _size.x;
			return std::span<const T>(line_begin, line_length);
		}
 
		constexpr T& at(std::size_t x, std::size_t y)
		{
			Position2D pos { .x = x, .y = y };
			if (!is_in_range(pos))
				throw details::OutOfRange();
			return (*this)[pos];
		}

		constexpr const T& at(std::size_t x, std::size_t y) const
		{
			Position2D pos { .x = x, .y = y};
			if (!is_in_range(pos))
				throw details::OutOfRange();
			return (*this)[pos];
		}

		constexpr T& at(Position2D pos)
		{
			if (!is_in_range(pos))
				throw details::OutOfRange();
			return (*this)[pos];
		}

		constexpr const T& at(Position2D pos) const
		{
			if (!is_in_range(pos))
				throw details::OutOfRange();
			return (*this)[pos];
		}

		constexpr T& operator[](Position2D pos)
		{
			return _container[pos.x + pos.y * _size.x];
		}

		constexpr const T& operator[](Position2D pos) const
		{
			return _container[pos.x + pos.y * _size.x];
		}

		constexpr T& operator()(std::size_t x, std::size_t y)
		{
			return _container[x +y * _size.x];
		}

		constexpr const T& operator()(std::size_t x, std::size_t y) const
		{
			return _container[x +y * _size.x];
		}

		constexpr const Size2D&	get_size() const { return _size; }

		constexpr bool is_in_range(const Position2D& pos) const
		{
			return
				pos.x < _size.x &&
				pos.y < _size.y;
		}

	private:
		Size2D			_size;
		std::vector<T>	_container;
};


} // namespace thuto