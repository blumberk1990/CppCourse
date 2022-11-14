# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")

add_library(commonLibrary ../src/personFactory.cpp)

add_executable(testRunner src/testRunner.cpp)
target_link_libraries(testRunner commonLibrary ${GTEST_LIBRARIES} pthread)
