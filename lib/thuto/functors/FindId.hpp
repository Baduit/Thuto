#pragma once

#include <concepts>

namespace thuto
{

template <typename T>
concept IdGetterSnakeCase = 
	requires(const T& t)
	{
		{ t.get_id() };
	};

template <typename T>
concept IdGetterCamelCase = 
	requires(const T& t)
	{
		{ t.getId() };
	};

template <typename T>
concept IdAttribute = 
	requires(const T& t)
	{
		{ t.id };
	};

template <std::equality_comparable IdType>
struct FindId
{
	FindId(IdType id_to_find):
		_id_to_find(id_to_find)
	{}

	template <IdGetterSnakeCase T>
	[[nodiscard]] bool operator()(const T& identifiable)
	{
		return identifiable.get_id() == _id_to_find;
	}

	template <IdGetterCamelCase T>
	[[nodiscard]] bool operator()(const T& identifiable)
	{
		return identifiable.getId() == _id_to_find;
	}

	template <IdAttribute T>
	[[nodiscard]] bool operator()(const T& identifiable)
	{
		return identifiable.id == _id_to_find;
	}

	IdType _id_to_find;
};

} // namespace thuto