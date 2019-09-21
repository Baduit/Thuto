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

# Args
add_executable(test_args_main.test ./test/Args/test_args_main.cpp)
add_test(test_args_main test_args_main.test)

# CondVar
add_executable(test_cond_var_main.test ./test/CondVar/test_cond_var_main.cpp)
add_test(test_cond_var_main test_cond_var_main.test)

# Counter
add_executable(test_counter.test ./test/Counter/test_counter_main.cpp)
add_test(test_counter test_counter.test)
target_link_libraries(test_counter.test ${CMAKE_THREAD_LIBS_INIT})

# Expected
add_executable(test_expected_main.test ./test/Expected/test_expected_main.cpp)
add_test(test_expected_main test_expected_main.test)

# NContainer
add_executable(test_n_container_main.test ./test/NContainer/test_n_container_main.cpp)
add_test(test_n_container_main test_n_container_main.test)

# StringView
add_executable(test_string_view_main.test ./test/StringView/test_string_view_main.cpp)
add_test(test_string_view_main test_string_view_main.test)

# Threadpool
add_executable(test_threadpool_main.test ./test/Threadpool/test_threadpool_main.cpp)
add_test(test_threadpool_main test_threadpool_main.test)

# Threadsafe
add_executable(test_thread_safe_main.test ./test/ThreadSafe/test_thread_safe_main.cpp)
add_test(test_thread_safe_main test_thread_safe_main.test)

# Timer
add_executable(test_advanded_clock.test ./test/Timer/test_advanded_clock_main.cpp)
add_test(test_advanded_clock test_advanded_clock.test)

add_executable(test_loop_thread_timer.test ./test/Timer/test_loop_thread_timer_main.cpp)
add_test(test_loop_thread_timer test_loop_thread_timer.test)
target_link_libraries(test_loop_thread_timer.test ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_simple_clock.test ./test/Timer/test_simple_clock_main.cpp)
add_test(test_simple_clock test_simple_clock.test)

add_executable(test_sleeper.test ./test/Timer/test_sleeper_main.cpp)
add_test(test_sleeper test_sleeper.test)
target_link_libraries(test_sleeper.test ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_thread_timer.test ./test/Timer/test_thread_timer_main.cpp)
add_test(test_thread_timer test_thread_timer.test)
target_link_libraries(test_thread_timer.test ${CMAKE_THREAD_LIBS_INIT})

# Variant
add_executable(test_variant_main.test ./test/Variant/test_variant_main.cpp)
add_test(test_variant_main test_variant_main.test)
