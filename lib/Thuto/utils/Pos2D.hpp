#include <compare>
#include <utility>


namespace thuto
{

template <typename T = std::size_t>
struct Position2D
{
	T x = 0;
	T y = 0;

	friend bool operator==(const Position2D& a, const Position2D& b) = default;
	friend std::strong_ordering operator<=>(const Position2D& a, const Position2D& b) = default;
};

} // namespace thuto
