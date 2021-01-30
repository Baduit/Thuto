#include <compare>
#include <utility>


namespace thuto
{

template <typename T>
struct BasicPosition2D
{
	T x = 0;
	T y = 0;

	constexpr friend bool operator==(const BasicPosition2D& a, const BasicPosition2D& b) = default;
	constexpr friend std::strong_ordering operator<=>(const BasicPosition2D& a, const BasicPosition2D& b) = default;
};

using Position2D = BasicPosition2D<std::size_t>;

} // namespace thuto
