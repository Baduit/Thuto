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
add_executable(counter_example ./example/Counter/counter_example_main.cpp)
target_link_libraries(counter_example ${CMAKE_THREAD_LIBS_INIT})

add_executable(timer_example ./example/Timer/timer_example_main.cpp)
target_link_libraries(timer_example ${CMAKE_THREAD_LIBS_INIT})


# Tests
enable_testing()

add_subdirectory(test)
