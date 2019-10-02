#pragma once

#include <type_traits>

#include "TypeHelperDetails.hpp"

namespace Thuto
{

template <typename ...With>
struct SfinaeHelperOperator_function_call_with
{
	template<typename T, typename _ = void>
	struct FunctionCallWith: std::false_type {};

	template<typename T>
	struct FunctionCallWith
	<
		T,
		std::conditional_t
		<
			false,
			Details::SfinaeHelper
			<
				decltype(std::declval<T>()(std::declval<With...>()))
			>,
			void
		>
	> : public std::true_type {};

};

template <typename T, typename ...With>
inline constexpr bool has_operator_function_call_with()
{
	using Type = SfinaeHelperOperator_function_call_with<With...>;
	using FinalType = typename Type::template FunctionCallWith<T>;

    if constexpr (std::is_base_of_v<std::true_type, FinalType>)
        return true;
    else
        return false;
}

struct MyDummy {};

void test_reve()
{
	has_operator_function_call_with<MyDummy, int, int>();
}

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


template <typename T>
inline constexpr bool has_operator_function_call()
{
    if constexpr (std::is_base_of_v<std::true_type, SfinaeHasOperator_function_call<T>>)
        return true;
    else
        return false;
}


}