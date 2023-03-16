cmake_minimum_required(VERSION 3.24)
project(Low_level_programming2)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC "src/*.h" "src/*.cpp" "src/structure/*.cpp" "src/structure/*.h")

add_executable(Low_level_programming2 ${SRC} src/main.cpp)