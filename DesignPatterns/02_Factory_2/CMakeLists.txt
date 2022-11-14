# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

project(02_Factory_2)

set(SOURCES src/main.cpp)

add_subdirectory(tests)
add_executable(02_Factory_2 ${SOURCES})
