#include <thuto/utils/Random.hpp>

namespace thuto
{


RandomEngine::RandomEngine():
	_mt(_rd())
{}

std::size_t RandomEngine::operator()(std::size_t max_value_included)
{
	std::uniform_int_distribution<std::size_t> dist(0, max_value_included);
	return dist(_mt);
}


std::size_t Random::rand(std::size_t max_value_included)
{
	return random_engine(max_value_included);
}

RandomEngine Random::random_engine = {};

} // namespace thuto