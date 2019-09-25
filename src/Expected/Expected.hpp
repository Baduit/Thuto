#pragma once

#include <variant>
#include <exception>
#include <string_view>
#include <type_traits>
#include <functional>
#include <optional>

#include "ValueWrapper.hpp"
#include "IsOneOf.hpp"

namespace Thuto
{

namespace
{

using Details::ValueWrapper;

template<typename T>
using GenericValueType = typename std::conditional<!std::is_reference_v<T>, ValueWrapper<T>, std::reference_wrapper<std::remove_reference_t<T>>>::type;

template <typename ReturnVariant, typename V>
ReturnVariant	get_value_from_variant(V&& v)
{
	std::optional<ReturnVariant> return_variant;
	v.visit([&] (auto&& value) { return_variant.emplace(std::move(value)); });
	return *return_variant;
}	

}	

template <typename ValueType, typename ...ErrorType>
class Expected
{
	private:
		using VariantType = std::variant<GenericValueType<ValueType>, ErrorType...>;

	public:
		constexpr Expected(Expected&& e) = default;

		//constexpr Expected(const ValueType& t): _variant(GenericValueType<ValueType>(t)) {}
		constexpr Expected(ValueType&& t): _variant(GenericValueType<ValueType>(std::forward<ValueType&&>(t))) {}

		template <typename Error, std::enable_if_t<IsOneOf<Error, ErrorType...>::value, int> = 0>
		constexpr Expected(const Error& e): _variant(e) {}

		template <typename Error, std::enable_if_t<IsOneOf<Error, ErrorType...>::value, int> = 0>
		constexpr Expected(Error&& e): _variant(std::forward<Error&&>(e)) {}

		template <typename ...OtherErrorType>
		constexpr Expected(Expected<ValueType, OtherErrorType...>&& other):
			_variant(get_value_from_variant<VariantType>(std::forward<Expected<ValueType, OtherErrorType...>&&>(other)))
		{
			static_assert(sizeof...(ErrorType) > sizeof...(OtherErrorType), "Expected error types do not match.");
		}

		constexpr ValueType& operator*() { return get(); }
		constexpr const ValueType& operator*() const { return get(); }

		constexpr std::remove_reference_t<ValueType>* operator->() { return &(std::get<0>(_variant).get()); }
		constexpr const std::remove_reference_t<ValueType>* operator->() const { return &(std::get<0>(_variant).get()); }

		constexpr ValueType& get() { return std::get<0>(_variant).get(); }
		constexpr const ValueType& get() const { return std::get<0>(_variant).get(); }

		template <typename T>
		constexpr auto&	get_by_type()
		{
			if constexpr (std::is_same_v<T, ValueType>)
				return get();
			else
				return std::get<T>(_variant);
		}

		template <typename T>
		constexpr const auto&	get_by_type() const
		{
			if constexpr (std::is_same_v<T, ValueType>)
				return get();
			else
				return std::get<T>(_variant);
		}

		template <std::size_t I>
		constexpr auto&	get_by_index()
		{
			if constexpr (I == 0)
				return get();
			else
				return std::get<I>(_variant);
		}

		template <std::size_t I>
		constexpr const auto&	get_by_index() const
		{
			if constexpr (I == 0)
				return get();
			else
				return std::get<I>(_variant);
		}

		constexpr std::size_t index() const { return _variant.index(); }

		constexpr ValueType& getOr(ValueType&& t)
		{
			if (_variant.index() == 0)
				return get();
			else
				return t;
		}

		constexpr ValueType& getOr(ValueType&& t) const
		{
			if (_variant.index() == 0)
				return get();
			else
				return t;
		}

        template <typename T>
        constexpr bool hold_alternative() const
        {
			if constexpr (std::is_same_v<T, ValueType>)
				return std::holds_alternative<GenericValueType<T>>(_variant);
			else
            	return std::holds_alternative<T>(_variant);
        }

		constexpr operator bool() const { return !_variant.index(); }

		template <typename T>
		constexpr bool operator==(const T& t)
		{
			// add a static assert to be sure that T is in the list and have a better error message
			if constexpr (std::is_reference_v<ValueType>)
			{
				if constexpr (std::is_const_v<std::remove_reference_t<ValueType>>)
				{
					if (hold_alternative<const T&>())
						return t == get_by_type<const T&>();
					else
						return false;
				}
				else
				{
					if (hold_alternative<T&>())
						return t == get_by_type<T&>();
					else
						return false;
				}
			}
			else
			{
				if (hold_alternative<T>())
					return t == get_by_type<T>();
				else
					return false;
			}
		}

		template <typename T>
		constexpr bool operator!=(const T& t)
		{
			return !(*this == t);
		}

		
		template <class Visitor>
		constexpr auto visit(Visitor&& visitor) { return std::visit(visitor, _variant); }

		template <class Visitor>
		constexpr auto visit(Visitor&& visitor) const { return std::visit(visitor, _variant); }

	private:
		VariantType _variant;
};

}