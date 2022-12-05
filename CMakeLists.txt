cmake_minimum_required(VERSION 3.22)
project(AdventOfCode2022 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
list(APPEND DAYS day1 day2 day3 day4 day5)

foreach(DAY ${DAYS})
    file(GLOB SOURCES ${DAY}/*.cpp)
    add_executable(${DAY} ${SOURCES})
    target_include_directories(${DAY} PRIVATE ${DAY} ${CMAKE_CURRENT_SOURCE_DIR})
    file(COPY ${DAY}/${DAY}input.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach()
