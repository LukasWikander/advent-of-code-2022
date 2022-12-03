cmake_minimum_required(VERSION 3.22)
project(AdventOfCode2022 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
list(APPEND DAYS day1 day2 day3)

foreach(DAY ${DAYS})
    file(GLOB SOURCES ${DAY}/*.cpp)
    add_executable(${DAY} ${SOURCES})
    file(COPY ${DAY}/${DAY}input.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach()


