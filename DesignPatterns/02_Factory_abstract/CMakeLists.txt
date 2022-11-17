# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

project(02_Factory_abstract)

set(SOURCES src/main.cpp 
            src/Coffee.cpp
            src/CoffeeFactory.cpp
            src/DrinkFactory.cpp
            src/Tea.cpp
            src/TeaFactory.cpp)

add_subdirectory(tests)
add_executable(02_Factory_abstract ${SOURCES})
