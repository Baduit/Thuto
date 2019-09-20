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

include_directories(Thutothmes PRIVATE
      ./src
    )

set(SRCS
    ./example/main.cpp
  )


add_executable(expected_example ${SRCS})


# Tests
enable_testing()

add_executable(test_test.test ./test/test_test.cpp)
add_test(test_test test_test.test)
