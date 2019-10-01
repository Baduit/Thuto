#pragma once

#include <type_traits>

#include "TypeHelperDetails.hpp"

namespace Thuto
{

template<typename T, typename _ = void>
struct SfinaeHasOperator_function_call : std::false_type {};

template<typename T>
struct SfinaeHasOperator_function_call
<
	T,
	std::conditional_t
	<
		false,
		Details::SfinaeHelper
		<
            decltype(&T::operator())
		>,
		void
	>
> : public std::true_type
{
};


template <typename T, typename With>
inline constexpr bool has_operator_function_call()
{
    if constexpr (std::is_base_of_v<std::true_type, SfinaeHasOperator_function_call<T>>)
        return true;
    else
        return false;
}



}