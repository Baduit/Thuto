#pragma once

// Can't use the generate macro apparently so here's a lot of copy past

#include <type_traits>

#include "TypeHelperDetails.hpp"

namespace Thuto
{

/*
** operator++()  // ++i
*/
template<typename T, typename _ = void>
struct SfinaeHasOperator_decrement_before : std::false_type {};

template<typename T>
struct SfinaeHasOperator_decrement_before
<
	T,
	std::conditional_t
	<
		false,
		Details::SfinaeHelper
		<
			decltype(std::declval<T>().operator++())
		>,
		void
	>
> : public std::true_type {};


template <typename T>
inline constexpr bool has_operator_decrement_before()
{
    if constexpr (std::is_base_of_v<std::true_type, SfinaeHasOperator_decrement_before<T>>)
        return true;
    else
        return false;
}

/*
** operator++(int) // i++
*/
template<typename T, typename _ = void>
struct SfinaeHasOperator_decrement_after : std::false_type {};

template<typename T>
struct SfinaeHasOperator_decrement_after
<
	T,
	std::conditional_t
	<
		false,
		Details::SfinaeHelper
		<
			decltype(std::declval<T>().operator++(std::declval<int>()))
		>,
		void
	>
> : public std::true_type {};


template <typename T>
inline constexpr bool has_operator_decrement_after()
{
    if constexpr (std::is_base_of_v<std::true_type, SfinaeHasOperator_decrement_after<T>>)
        return true;
    else
        return false;
}

/*
** Both decrement at once
*/
template <typename T>
inline constexpr bool has_operators_decrement()
{
    return has_operator_decrement_after<T>() && has_operator_decrement_before<T>();
}


}
