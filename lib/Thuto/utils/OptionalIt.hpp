#pragma once

#include <iterator>

namespace thuto
{

template <typename It, typename Sentinel> requires std::sentinel_for<It, Sentinel>
class OptionalIt
{
	public:
		OptionalIt(It it, Sentinel end):
			_it(it),
			_end(end)
		{}

		OptionalIt(const OptionalIt&) = default;
		OptionalIt& operator=(const OptionalIt&) = default;

		OptionalIt(OptionalIt&&) = default;
		OptionalIt& operator=(OptionalIt&&) = default;

	explicit operator bool() const { return _it != _end; }

	It& operator->() { return _it; }
	const It& operator->() const { return _it; }

	auto& operator*() { return *_it; }
	const auto& operator*() const { return *_it; }

	private:
		It _it;
		Sentinel _end;
};

} // namespace thuto