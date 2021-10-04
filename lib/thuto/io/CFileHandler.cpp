#include <thuto/io/CFileHandler.hpp>

namespace thuto
{

void CFileHandler::Deleter::operator()(std::FILE* handle) const
{
	std::fclose(handle);
}

CFileHandler::CFileHandler(std::FILE* handle):
	_handle(handle)
{}

CFileHandler::operator bool()
{
	return
		_handle &&
		error() == 0 &&
		eof() == 0;
}

void CFileHandler::close()
{
	std::fclose(_handle.get());
	_handle.reset();

}

void CFileHandler::flush()
{
	std::fflush(_handle.get());
}

std::size_t CFileHandler::read(void* buffer, std::size_t size, std::size_t count)
{
	return std::fread(buffer, size, count, _handle.get());
}

std::size_t CFileHandler::write(const void* buffer, std::size_t size, std::size_t count)
{
	return std::fwrite(buffer, size, count, _handle.get());
}

std::FILE* CFileHandler::get_handle()
{
	return _handle.get();
}

const std::FILE* CFileHandler::get_handle() const
{
	return _handle.get();
}

std::FILE* CFileHandler::release_handle()
{
	return _handle.release();
}

void CFileHandler::swap(CFileHandler& other)
{
	_handle.swap(other._handle);
}

int CFileHandler::error()
{
	return std::ferror(_handle.get());
}

int CFileHandler::eof()
{
	return std::feof(_handle.get());
}

} // namespace thuto