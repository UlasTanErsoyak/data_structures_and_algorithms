cmake_minimum_required(VERSION 3.12)
project(nn)
include_directories(include)
add_compile_options(-g -Wall -Wextra -Wpedantic)
set(HEADERS
    src/include/bmp_image.h
    src/include/custom_math.h
)

set(SOURCES
    src/main.c
    src/bmp_image.c
    src/custom_math.c
)
add_executable(run ${SOURCES} ${HEADERS})