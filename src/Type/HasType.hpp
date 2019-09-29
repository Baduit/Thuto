#pragma once

#pragma once

#pragma once

#include <type_traits>

#include "TypeHelperDetails.hpp"

#ifdef THUTO_GENERATE_HAS_TYPE
	static_assert(false, "Macro \"THUTO_HAS_METHOD\" already defined!")
#endif


#define THUTO_GENERATE_HAS_TYPE(type_name) template<typename T, typename _ = void>											\
										struct SfinaeHasType_##type_name : std::false_type {};								\
																																\
										template<typename T>																	\
										struct SfinaeHasType_##type_name													\
										<																						\
											T,																					\
											std::conditional_t																	\
											<																					\
												false,																			\
												Details::SfinaeHelper																	\
												<																				\
													decltype(T::type_name)									\
												>,																				\
												void																			\
											>																					\
										> : public std::true_type {};															\
																																\
										template <typename T>																	\
										inline constexpr bool has_type_##type_name()										\
										{																						\
											if constexpr (std::is_base_of_v<std::true_type, SfinaeHasType_##type_name<T>>)	\
												return true;																	\
											else																				\
												return false;																	\
										}


namespace Thuto
{
THUTO_GENERATE_HAS_TYPE(value_type)
}