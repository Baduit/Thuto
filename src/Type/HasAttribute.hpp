#pragma once

#include <type_traits>

#include "TypeHelperDetails.hpp"

#ifdef THUTO_GENERATE_HAS_ATTRIBUTE
	static_assert(false, "Macro \"THUTO_HAS_METHOD\" already defined!")
#endif


#define THUTO_GENERATE_HAS_ATTRIBUTE(attribute_name) template<typename T, typename _ = void>											\
										struct SfinaeHasAttribute_##attribute_name : std::false_type {};								\
																																\
										template<typename T>																	\
										struct SfinaeHasAttribute_##attribute_name													\
										<																						\
											T,																					\
											std::conditional_t																	\
											<																					\
												false,																			\
												Details::SfinaeHelper																	\
												<																				\
													decltype(std::declval<T>().attribute_name)									\
												>,																				\
												void																			\
											>																					\
										> : public std::true_type {};															\
																																\
										template <typename T>																	\
										inline constexpr bool has_attribute_##attribute_name()										\
										{																						\
											if constexpr (std::is_base_of_v<std::true_type, SfinaeHasAttribute_##attribute_name<T>>)	\
												return true;																	\
											else																				\
												return false;																	\
										}


namespace Thuto
{
THUTO_GENERATE_HAS_ATTRIBUTE(x)
THUTO_GENERATE_HAS_ATTRIBUTE(y)
THUTO_GENERATE_HAS_ATTRIBUTE(z)
THUTO_GENERATE_HAS_ATTRIBUTE(width)
THUTO_GENERATE_HAS_ATTRIBUTE(height)
}