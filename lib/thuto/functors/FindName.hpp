#pragma once

#include <concepts>

namespace thuto
{

template <typename T>
concept NameGetterSnakeCase = 
	requires(const T& t)
	{
		{ t.get_name() };
	};

template <typename T>
concept NameGetterCamelCase = 
	requires(const T& t)
	{
		{ t.getName() };
	};

template <typename T>
concept NameAttribute = 
	requires(const T& t)
	{
		{ t.name};
	};

template <std::equality_comparable NameType>
struct FindName
{
	FindName(NameType name_to_find):
		_name_to_find(name_to_find)
	{}

	template <NameGetterSnakeCase T>
	[[nodiscard]] bool operator()(const T& named)
	{
		return named.get_name() == _name_to_find;
	}

	template <NameGetterCamelCase T>
	[[nodiscard]] bool operator()(const T& named)
	{
		return named.getName() == _name_to_find;
	}

	template <NameAttribute T>
	[[nodiscard]] bool operator()(const T& named)
	{
		return named.name == _name_to_find;
	}

	NameType _name_to_find;
};

} // namespace thuto