#pragma once

#include <type_traits>
#include <utility>

#include "TypeHelperDetails.hpp"


namespace Thuto
{

namespace Details
{

template <typename Pair, std::size_t Index>
using TypeInPair = decltype(std::get<Index>(std::declval<Pair>()));

}

template<typename Pair, typename _ = void>
struct SfinaeHasOperator_addition_with : std::false_type {};

template<typename Pair>
struct SfinaeHasOperator_addition_with
<
	Pair,
	std::conditional_t
	<
		false,
		Details::SfinaeHelper
		<
            decltype(std::declval<Details::TypeInPair<Pair, 0>>() + std::declval<Details::TypeInPair<Pair, 1>>())
		>,
		void
	>
> : public std::true_type
{
};


template <typename T, typename With>
inline constexpr bool has_operator_addition_with()
{
    if constexpr (std::is_base_of_v<std::true_type, SfinaeHasOperator_addition_with<std::pair<T, With>>>)
        return true;
    else
        return false;
}

}