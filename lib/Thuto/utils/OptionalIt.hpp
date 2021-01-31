#pragma once

#include <iterator>

namespace thuto
{

template <typename It, typename Sentinel> requires std::sentinel_for<It, Sentinel>
class OptionalIt
{
	public:
		constexpr OptionalIt(It it, Sentinel end):
			_it(it),
			_end(end)
		{}

		constexpr OptionalIt(const OptionalIt&) = default;
		constexpr OptionalIt& operator=(const OptionalIt&) = default;

		constexpr OptionalIt(OptionalIt&&) = default;
		constexpr OptionalIt& operator=(OptionalIt&&) = default;

		[[nodiscard]] constexpr explicit operator bool() const { return _it != _end; }

		constexpr It& operator->() { return _it; }
		constexpr const It& operator->() const { return _it; }

		[[nodiscard]] constexpr auto& operator*() { return *_it; }
		[[nodiscard]] constexpr const auto& operator*() const { return *_it; }

	private:
		It _it;
		Sentinel _end;
};

} // namespace thuto