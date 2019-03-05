cmake_minimum_required(VERSION 3.10)
project(Book_Example)

set(CMAKE_CXX_STANDARD 14)

add_executable(Book_Example main.cpp node.cpp node.h linkedBag.cpp linkedBag.h bagInterface.cpp bagInterface.h)