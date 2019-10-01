#pragma once

#include <type_traits>

#include "TypeHelperDetails.hpp"

#ifdef THUTO_GENERATE_HAS_METHOD
	static_assert(false, "Macro \"THUTO_HAS_METHOD\" already defined!")
#endif

#define THUTO_GENERATE_HAS_METHOD(method_name) template<typename T, typename _ = void>											\
										struct SfinaeHasMethod_##method_name : std::false_type {};								\
																																\
										template<typename T>																	\
										struct SfinaeHasMethod_##method_name													\
										<																						\
											T,																					\
											std::conditional_t																	\
											<																					\
												false,																			\
												Details::SfinaeHelper																	\
												<																				\
													decltype(&T::method_name)									\
												>,																				\
												void																			\
											>																					\
										> : public std::true_type {};															\
																																\
										template <typename T>																	\
										inline constexpr bool has_method_##method_name()										\
										{																						\
											if constexpr (std::is_base_of_v<std::true_type, SfinaeHasMethod_##method_name<T>>)	\
												return true;																	\
											else																				\
												return false;																	\
										}


namespace Thuto
{
THUTO_GENERATE_HAS_METHOD(size)
THUTO_GENERATE_HAS_METHOD(data)
THUTO_GENERATE_HAS_METHOD(begin)
THUTO_GENERATE_HAS_METHOD(cbegin)
THUTO_GENERATE_HAS_METHOD(end)
THUTO_GENERATE_HAS_METHOD(cend)
THUTO_GENERATE_HAS_METHOD(length)
THUTO_GENERATE_HAS_METHOD(at)
THUTO_GENERATE_HAS_METHOD(front)
THUTO_GENERATE_HAS_METHOD(back)
THUTO_GENERATE_HAS_METHOD(empty)
}