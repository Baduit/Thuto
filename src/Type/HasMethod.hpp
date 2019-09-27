#pragma once

#include <type_traits>

#ifdef THUTO_HAS_METHOD
	static_assert(false, "Macro \"THUTO_HAS_METHOD\" already defined!")
#endif


template<typename... Ts>
struct SfinaeHelper {};

#define THUTO_GENERATE_HAS_METHOD(method_name) 	template<typename T, typename _ = void>											\
										struct SfinaeHasMethod_##method_name : std::false_type {};								\
																																\
										template<typename T>																	\
										struct SfinaeHasMethod_##method_name													\
										<																						\
											T,																					\
											std::conditional_t																	\
											<																					\
												false,																			\
												SfinaeHelper																	\
												<																				\
													decltype(std::declval<T>().method_name())									\
												>,																				\
												void																			\
											>																					\
										> : public std::true_type {};															\
																																\
										template <typename T>																	\
										inline constexpr bool has_##method_name()												\
										{																						\
											if constexpr (std::is_base_of_v<std::true_type, SfinaeHasMethod_##method_name<T>>)	\
												return true;																	\
											else																				\
												return false;																	\
										}													


THUTO_GENERATE_HAS_METHOD(size)