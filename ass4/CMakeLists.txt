cmake_minimum_required(VERSION 3.10)
project(ass4)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "-g -std=c++14 -Wall -Wextra")

add_executable(ass4 ass4.cpp skiplist.cpp skiplist.h)