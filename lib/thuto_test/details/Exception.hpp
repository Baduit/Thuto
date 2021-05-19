#pragma once

#include <stdexcept>

namespace thuto::details
{

class Exception : public std::exception
{
	public:
		Exception(const std::string& what_arg):
			_exception(what_arg)
		{}

		Exception(const char* what_arg):
			_exception(what_arg)
		{}

		Exception(const Exception&) noexcept = default;
		Exception& operator=(const Exception&) noexcept = default;

	    virtual const char* what() const noexcept override
		{
			return _exception.what();
		}

		// When source location is available add a where method


	private:
		// I use a std::runtime_error just to store the string
		// because the operator= of an exception must be noexcept
		std::runtime_error _exception;
};

class OutOfRange : public Exception
{
	public:
		// When source location is available use it
		OutOfRange():
			Exception("Out of range.")
		{}

		OutOfRange(const OutOfRange&) noexcept = default;
		OutOfRange& operator=(const OutOfRange&) noexcept = default;
};

} // namespace thuto::details