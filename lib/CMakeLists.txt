set(SRCS ./Thuto/Thuto.cpp)


add_library(Thuto ${SRCS})

target_compile_features(Thuto PUBLIC cxx_std_20)

target_compile_options(Thuto
                       PRIVATE
                       $<$<CXX_COMPILER_ID:MSVC>:/W3 /permissive- /TP>
                       $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wextra -Wall -Wsign-conversion -Wfloat-equal -pedantic -Wredundant-decls -Wshadow -Wpointer-arith -O3>)

target_include_directories(Thuto PUBLIC ${CMAKE_CURRENT_LIST_DIR})