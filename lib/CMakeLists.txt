add_library(Thuto INTERFACE)
target_compile_features(Thuto INTERFACE cxx_std_20)
target_compile_options(Thuto
                       INTERFACE
                       $<$<CXX_COMPILER_ID:MSVC>:/W3 /permissive- /TP>
                       $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wextra -Wall -Wsign-conversion -Wfloat-equal -pedantic -Wredundant-decls -Wpointer-arith -O3>)
target_include_directories(Thuto INTERFACE ${CMAKE_CURRENT_LIST_DIR})