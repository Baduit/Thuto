add_executable(test_has.test test_has_main.cpp)
add_test(test_has test_has.test)

add_executable(arithmetic.test operator/arithmetic_main.cpp)
add_test(arithmetic arithmetic.test)

add_executable(bitwise.test operator/bitwise_main.cpp)
add_test(bitwise bitwise.test)

add_executable(comparison.test operator/comparison_main.cpp)
add_test(comparison comparison.test)

add_executable(compound.test operator/compound_main.cpp)
add_test(compound compound.test)

add_executable(logical.test operator/logical_main.cpp)
add_test(logical logical.test)

add_executable(other.test operator/other_main.cpp)
add_test(other other.test)