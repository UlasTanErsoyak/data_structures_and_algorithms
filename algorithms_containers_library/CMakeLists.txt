cmake_minimum_required(VERSION 3.12)
project(container_algorithm_std)
set(CMAKE_CXX_STANDARD 20)
include_directories(include)

set(HEADERS
    include/array.hh
    
)

set(SOURCES
    src/main.cpp

)
add_executable(run ${SOURCES} ${HEADERS})