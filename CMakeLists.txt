cmake_minimum_required(VERSION 3.12)
project(compiler)
include_directories(include)

set(HEADERS
    src/include/token.hpp
    src/include/lexer.hpp
    src/include/parser.hpp
    src/include/io.hpp
)

set(SOURCES
    src/main.cpp
    src/lexer.cpp
    src/parser.cpp
)
add_executable(run ${SOURCES} ${HEADERS})