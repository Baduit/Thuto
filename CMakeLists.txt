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

add_executable(test_args_main.test ./test/Args/test_args_main.cpp)
add_test(test_args_main test_args_main.test)

add_executable(test_cond_var_main.test ./test/CondVar/test_cond_var_main.cpp)
add_test(test_cond_var_main test_cond_var_main.test)

add_executable(test_counter_main.test ./test/Counter/test_counter_main.cpp)
add_test(test_counter_main test_counter_main.test)

add_executable(test_expected_main.test ./test/Expected/test_expected_main.cpp)
add_test(test_expected_main test_expected_main.test)

add_executable(test_n_container_main.test ./test/NContainer/test_n_container_main.cpp)
add_test(test_n_container_main test_n_container_main.test)

add_executable(test_string_view_main.test ./test/StringView/test_string_view_main.cpp)
add_test(test_string_view_main test_string_view_main.test)

add_executable(test_threadpool_main.test ./test/Threadpool/test_threadpool_main.cpp)
add_test(test_threadpool_main test_threadpool_main.test)

add_executable(test_thread_safe_main.test ./test/ThreadSafe/test_thread_safe_main.cpp)
add_test(test_thread_safe_main test_thread_safe_main.test)

add_executable(test_timer_main.test ./test/Timer/test_timer_main.cpp)
add_test(test_timer_main test_timer_main.test)

add_executable(test_variant_main.test ./test/Variant/test_variant_main.cpp)
add_test(test_variant_main test_variant_main.test)
