cmake_minimum_required(VERSION 3.22)
project(AdventOfCode2022 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(day1 day1/main.cpp)
file(COPY day1/day1input.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

