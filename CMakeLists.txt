cmake_minimum_required(VERSION 3.17)
project(testie)

set(CMAKE_CXX_STANDARD 20)

add_executable(testie test.cpp contains_method.h)