#pragma once

namespace Thuto
{

namespace Details
{
template <typename T>
class ValueWrapper
{
	public:
		constexpr ValueWrapper() = delete;

		constexpr ValueWrapper(const T& t): _value(t) {}
		constexpr ValueWrapper(T&& t): _value(std::move(t)) {}

		constexpr ValueWrapper(const ValueWrapper& other) = default;
		constexpr ValueWrapper& operator=(const ValueWrapper& other) = default;

		constexpr ValueWrapper(ValueWrapper&& other) = default;
		constexpr ValueWrapper& operator=(ValueWrapper&& other) = default;

		constexpr T&	get() { return _value; }
		constexpr const T&	get() const { return _value; }

		constexpr operator T& () { return _value; }
		constexpr operator const T& () const { return _value; }

	private:
		T _value;
};

}

}