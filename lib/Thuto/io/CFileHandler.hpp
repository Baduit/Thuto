#pragma once

#include <cstdio>
#include <memory>
#include <ranges>
#include <type_traits>
#include <concepts>

namespace thuto
{

// It is just a thin wrapper around a FILE
// It does not handle the creation, because if you want to open a file, just use c++ filestream
// It is intended to be used when you call a fonction (over which you have no control or can't change the API)
// that returns a FILE*
// We could add a lot of method, but it does not aimed to be exhaustive over all function taking a std::FILE*
// It is still possible to access the underlying std::FILE* with the method CFileHandler::get_handle()

template <typename T>
concept WritableElement = 
	std::has_unique_object_representations_v<T> &&
	!std::ranges::contiguous_range<T> &&
	!std::is_pointer_v<T>;

template <typename T>
concept WritableRange =
	std::ranges::contiguous_range<T> &&
	WritableElement<typename T::range_value_t>;



class CFileHandler
{
	struct Deleter
	{
		void operator()(std::FILE* handle) const;
	};

	public:
		CFileHandler() = default;
		CFileHandler(std::FILE* handle);

		CFileHandler(const CFileHandler&) = delete;
		CFileHandler& operator=(const CFileHandler&) = delete;

		CFileHandler(CFileHandler&&) = default;
		CFileHandler& operator=(CFileHandler&&) = default;

		operator bool();

		void close();
		void flush();

		std::size_t read(void* buffer, std::size_t size, std::size_t count);
		std::size_t write(const void* buffer, std::size_t size, std::size_t count);

		template <WritableRange Range>
		std::size_t read(const Range& r, std::size_t count)
		{
			using Element = typename Range::range_value_t;
			return read(std::ranges::data(r), sizeof(Element), count);
		}

		template <WritableRange Range>
		std::size_t read(const Range& r)
		{
			return read(r, std::ranges::size(r));
		}

		template <WritableRange Range>
		std::size_t write(const Range& r, std::size_t count)
		{
			using Element = typename Range::range_value_t;
			return write(std::ranges::data(r), sizeof(Element), count);
		}

		template <WritableRange Range>
		std::size_t write(const Range& r)
		{
			return write(r, std::ranges::size(r));
		}

		std::FILE* get_handle();
		const std::FILE* get_handle() const;

		std::FILE* release_handle();

		void swap(CFileHandler& other);

		int error();
		int eof();

	private:
		std::unique_ptr<std::FILE, Deleter> _handle = nullptr;
};

} // namespace thuto