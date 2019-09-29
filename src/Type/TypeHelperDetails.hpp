#pragma once

#include <utility>

namespace Thuto
{

namespace Details
{

template<typename... Ts>
struct SfinaeHelper {};

template <typename Pair, std::size_t Index>
using TypeIn = decltype(std::get<Index>(std::declval<Pair>()));

}

}