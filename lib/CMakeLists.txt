
set(SRCS
    ${CMAKE_CURRENT_LIST_DIR}/Thuto/details/Exception.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Thuto/process/Popen.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Thuto/utils/Clock.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Thuto/utils/Env.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Thuto/utils/Random.cpp
)

add_library(Thuto  ${SRCS})
target_compile_features(Thuto PUBLIC cxx_std_20)
target_compile_options(Thuto
                       PRIVATE
                       $<$<CXX_COMPILER_ID:MSVC>:/W3 /permissive- /TP>
                       $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wextra -Wall -Wsign-conversion -Wfloat-equal -pedantic -Wredundant-decls -Wpointer-arith -O3>)
target_include_directories(Thuto PUBLIC ${CMAKE_CURRENT_LIST_DIR})