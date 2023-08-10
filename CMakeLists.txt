cmake_minimum_required(VERSION 3.12)
project(compiler)
include_directories(include)

set(HEADERS
    src/include/bmp_image.h
)

set(SOURCES
    src/main.c
    src/bmp_image.c
)
add_executable(run ${SOURCES} ${HEADERS})