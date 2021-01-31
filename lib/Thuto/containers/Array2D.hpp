#pragma once

#include <array>
#include <span>
#include <ranges>

#include <Thuto/utils/Pos2D.hpp>
#include <Thuto/utils/Size2D.hpp>
#include <Thuto/details/Exception.hpp>

namespace thuto
{

template <typename T, std::size_t Width, std::size_t Height>
class Array2D
{
	public:
		constexpr Array2D() = default;

		constexpr Array2D(const Array2D&) = default;
		constexpr Array2D& operator=(const Array2D&) = default;

		constexpr Array2D(Array2D&&) = default;
		constexpr Array2D& operator=(Array2D&&) = default;

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


		auto begin() { return _container.begin(); }
		auto end() { return _container.end(); }

		auto cbegin() const { return _container.cbegin(); }
		auto cend() const { return _container.cend(); }

		auto rbegin() { return _container.rbegin(); }
		auto rend() { return _container.rend(); }

		auto crbegin() const { return _container.crbegin(); }
		auto crend() const { return _container.crend(); }


	private:
		std::array<T, Width * Height> _container;
};

} // namespace thuto