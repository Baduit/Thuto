#include <compare>
#include <utility>


namespace thuto
{

template <typename T = std::size_t>
struct Size2D
{
	T x = 0;
	T y = 0;

	friend bool operator==(const Size2D& a, const Size2D& b) = default;
	friend std::strong_ordering operator<=>(const Size2D& a, const Size2D& b) = default;
};

} // namespace thuto