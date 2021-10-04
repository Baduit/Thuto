#pragma once

#include <random>

namespace thuto
{

struct RandomEngine
{
	RandomEngine();

	[[nodiscard]] std::size_t operator()(std::size_t max_value_included);

	std::random_device	_rd;
	std::mt19937		_mt;
};

struct Random
{
	[[nodiscard]] static std::size_t rand(std::size_t max_value_included);
	
	static RandomEngine random_engine;
};

} // namespace thuto