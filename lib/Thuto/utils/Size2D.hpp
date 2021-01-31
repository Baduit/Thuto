#include <compare>
#include <utility>


namespace thuto
{

template <typename T>
struct BasicSize2D
{
	T x = 0;
	T y = 0;

	constexpr friend bool operator==(const BasicSize2D& a, const BasicSize2D& b) = default;
	constexpr friend std::strong_ordering operator<=>(const BasicSize2D& a, const BasicSize2D& b) = default;
};

using Size2D = BasicSize2D<std::size_t> ;

} // namespace thuto