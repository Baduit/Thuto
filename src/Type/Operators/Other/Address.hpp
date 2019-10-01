#pragma once

#include <type_traits>

#include "TypeHelperDetails.hpp"

namespace Thuto
{

template<typename T, typename _ = void>
struct SfinaeHasOperator_address : std::false_type {};

template<typename T>
struct SfinaeHasOperator_address
<
	T,
	std::conditional_t
	<
		false,
		Details::SfinaeHelper
		<
            decltype(&(std::declval<T>()))
		>,
		void
	>
> : public std::true_type
{
};


template <typename T, typename With>
inline constexpr bool has_operator_address()
{
    if constexpr (std::is_base_of_v<std::true_type, SfinaeHasOperator_address<T>>)
        return true;
    else
        return false;
}

}