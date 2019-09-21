add_executable(test_advanded_clock.test test_advanded_clock_main.cpp)
add_test(test_advanded_clock test_advanded_clock.test)

add_executable(test_loop_thread_timer.test test_loop_thread_timer_main.cpp)
add_test(test_loop_thread_timer test_loop_thread_timer.test)
target_link_libraries(test_loop_thread_timer.test ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_simple_clock.test test_simple_clock_main.cpp)
add_test(test_simple_clock test_simple_clock.test)

add_executable(test_sleeper.test test_sleeper_main.cpp)
add_test(test_sleeper test_sleeper.test)
target_link_libraries(test_sleeper.test ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_thread_timer.test test_thread_timer_main.cpp)
add_test(test_thread_timer test_thread_timer.test)
target_link_libraries(test_thread_timer.test ${CMAKE_THREAD_LIBS_INIT})
