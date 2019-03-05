cmake_minimum_required(VERSION 3.10)
project(ass3_3_)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "-g -std=c++14 -Wall -Wextra")

add_executable(ass3 ass3.cpp maze.cpp maze.h creature.cpp creature.h)