cmake_minimum_required(VERSION 3.10)
project(Hello_World)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "-g -std=c++14 -Wall -Wextra")

add_executable(Hello_World main.cpp)