#include <compare>
#include <utility>


namespace thuto
{

struct Position2D
{
	std::size_t x = 0;
	std::size_t y = 0;

	friend bool operator==(const Position2D& a, const Position2D& b) = default;
	friend std::strong_ordering operator<=>(const Position2D& a, const Position2D& b) = default;
};

} // namespace thuto
