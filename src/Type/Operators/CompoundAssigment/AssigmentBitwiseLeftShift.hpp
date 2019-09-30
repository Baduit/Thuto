#pragma once

#include <type_traits>

#include "TypeHelperDetails.hpp"

namespace Thuto
{

template<typename Pair, typename _ = void>
struct SfinaeHasOperator_assigment_left_shift_with : std::false_type {};

template<typename Pair>
struct SfinaeHasOperator_assigment_left_shift_with
<
	Pair,
	std::conditional_t
	<
		false,
		Details::SfinaeHelper
		<
            decltype(std::declval<Details::TypeIn<Pair, 0>>() <<= std::declval<Details::TypeIn<Pair, 1>>())
		>,
		void
	>
> : public std::true_type
{
};


template <typename T, typename With>
inline constexpr bool has_operator_assigment_left_shift_with()
{
    if constexpr (std::is_base_of_v<std::true_type, SfinaeHasOperator_assigment_left_shift_with<std::pair<T, With>>>)
        return true;
    else
        return false;
}

}