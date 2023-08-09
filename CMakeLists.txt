cmake_minimum_required(VERSION 3.12)
project(compiler)
include_directories(include)

set(HEADERS
)

set(SOURCES
    src/main.c
)
add_executable(run ${SOURCES} ${HEADERS})