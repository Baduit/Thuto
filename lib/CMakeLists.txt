set(SRCS
    ${CMAKE_CURRENT_LIST_DIR}/thuto/details/Exception.cpp
    ${CMAKE_CURRENT_LIST_DIR}/thuto/process/Popen.cpp
    ${CMAKE_CURRENT_LIST_DIR}/thuto/utils/Clock.cpp
    ${CMAKE_CURRENT_LIST_DIR}/thuto/utils/Env.cpp
    ${CMAKE_CURRENT_LIST_DIR}/thuto/utils/Random.cpp
    ${CMAKE_CURRENT_LIST_DIR}/thuto/io/CFileHandler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/thuto/io/file.cpp
)

add_library(thuto  ${SRCS})
target_compile_features(thuto PUBLIC cxx_std_20)
target_compile_options(thuto
                       PRIVATE
                       $<$<CXX_COMPILER_ID:MSVC>:/W3 /permissive- /TP>
                       $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wextra -Wall -Wsign-conversion -Wfloat-equal -pedantic -Wredundant-decls -Wpointer-arith -O3>)
target_include_directories(thuto PUBLIC ${CMAKE_CURRENT_LIST_DIR})
