cmake_minimum_required(VERSION 3.25)
project(graph_algorithm LANGUAGES C)
add_compile_options(-Wall -Wextra -Wpedantic)

set(SOURCES
    source/input.c
    source/algorithms.c
    source/main.c
)
add_executable(graph_algorithm ${SOURCES})
target_include_directories(graph_algorithm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)