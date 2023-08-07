cmake_minimum_required(VERSION 3.12)
project(compiler)
include_directories(include)

set(HEADERS
    src/include/token.hpp
    src/include/lexer.hpp
)

set(SOURCES
    src/main.cpp
    src/lexer.cpp

)
add_executable(run ${SOURCES} ${HEADERS})