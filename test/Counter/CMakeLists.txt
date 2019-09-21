add_executable(test_counter.test test_counter_main.cpp)
add_test(test_counter test_counter.test)
target_link_libraries(test_counter.test ${CMAKE_THREAD_LIBS_INIT})