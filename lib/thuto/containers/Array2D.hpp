#pragma once

#include <array>
#include <span>
#include <ranges>

#include <thuto/utils/Pos2D.hpp>
#include <thuto/utils/Size2D.hpp>
#include <thuto/details/Exception.hpp>

namespace thuto
{

// No container adoptor to keep the aggregate initialization simpler
template <typename T, std::size_t Width, std::size_t Height>
struct Array2D
{
	constexpr std::span<T> get_line(std::size_t line_number)
	{
		auto line_begin = &at(0, line_number);
		auto line_length = Width;
		return std::span<T>(line_begin, line_length);
	}

	constexpr std::span<const T> get_line(std::size_t line_number) const
	{
		auto line_begin = &at(0, line_number);
		auto line_length = Width;
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
		return _container[pos.x + pos.y * Width];
	}

	constexpr const T& operator[](Position2D pos) const
	{
		return _container[pos.x + pos.y * Width];
	}

	constexpr T& operator()(std::size_t x, std::size_t y)
	{
		return _container[x + y * Width];
	}

	constexpr const T& operator()(std::size_t x, std::size_t y) const
	{
		return _container[x + y * Width];
	}

	constexpr Size2D	get_size() const { return Size2D{ .x = Width, .y = Height }; }

	// be carefull to not resize the undelying container, it could easily cause some bugs
	constexpr auto& get_container() noexcept { return _container; }
	constexpr const auto& get_container() const noexcept { return _container; }

	constexpr bool is_in_range(const Position2D& pos) const
	{
		return
			pos.x < Width &&
			pos.y < Height;
	}


	constexpr auto begin() { return _container.begin(); }
	constexpr auto end() { return _container.end(); }

	constexpr auto cbegin() const { return _container.cbegin(); }
	constexpr auto cend() const { return _container.cend(); }

	constexpr auto rbegin() { return _container.rbegin(); }
	constexpr auto rend() { return _container.rend(); }

	constexpr auto crbegin() const { return _container.crbegin(); }
	constexpr auto crend() const { return _container.crend(); }

	std::array<T, Width * Height> _container;
};

} // namespace thuto