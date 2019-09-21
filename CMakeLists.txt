# TODO: make a real cmake for header only library

cmake_minimum_required(VERSION 3.9)
project(Thuto VERSION 0.1 DESCRIPTION "C++17 utility header-only library")

# Flags
if (UNIX)
	add_definitions(-Wextra -Wall -Wsign-conversion -Wfloat-equal -pedantic -Wredundant-decls -Wshadow -Wpointer-arith -g)
endif (UNIX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

find_package(Threads)

include_directories(Thutothmes PRIVATE
      ./src
      ./src/Expected
      ./src/Args
      ./src/CondVar
      ./src/Counter
      ./src/NContainer
      ./src/StringView
      ./src/Threadpool
      ./src/ThreadSafe
      ./src/Timer
      ./src/Variant
    )


# Examples
add_subdirectory(example)
# TODO: Later copy the examples in a folder easier to access?

# Tests
enable_testing(MAKE_DIRECTORY test)
add_subdirectory(test)
