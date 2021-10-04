#pragma once

#include <cstdint>
#include <compare>
#include <ostream>
#include <limits>

namespace thuto
{

class Id final
{
	public:
		constexpr Id() = default;
		constexpr explicit Id(uint64_t i): value(i) {}
		constexpr Id(const Id&) = default;
		constexpr Id(Id&&) = default;
		constexpr Id& operator=(const Id&) = default;
		constexpr Id& operator=(Id&&) = default;
		~Id() = default;

		constexpr bool operator==(const Id&) const = default;
		constexpr auto operator<=>(const Id&) const = default;

		// Maybe later randomize so people can't guess id
		[[nodiscard]] static Id generate() { return Id(next_id_value++); }

		[[nodiscard]] constexpr uint64_t operator*() const { return get_value(); }
		[[nodiscard]] constexpr uint64_t get_value() const { return value; }

	private:
		uint64_t value = 0;
		inline static uint64_t next_id_value = 0;
};

constexpr Id INVALID_ID = Id(18446744073709551615ull); // MSVC bug on std::numeric_limits<uint64_t>::max();

inline std::ostream& operator<<(std::ostream& os, const Id& id)
{
	os << *id;
	return os;
}


} // namespace thuto