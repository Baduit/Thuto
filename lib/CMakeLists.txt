add_library(Thuto INTERFACE)
target_compile_features(Thuto INTERFACE cxx_std_20)
target_include_directories(Thuto INTERFACE ${CMAKE_CURRENT_LIST_DIR})
