cmake_minimum_required(VERSION 3.10)
project(ass1)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "-g -std=c++14 -Wall -Wextra")

add_executable(ass1 ass1.cpp library.cpp library.h)