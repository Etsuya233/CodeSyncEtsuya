cmake_minimum_required(VERSION 3.23)
project(test1)

set(CMAKE_CXX_STANDARD 14)

MATH(EXPR stack_size "8*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(test1 Graph.h)
