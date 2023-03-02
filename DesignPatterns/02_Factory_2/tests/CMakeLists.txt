# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)
project(TestFactory)
# Include diretories
include_directories(/usr/include)
link_directories(/usr/lib)

# add definitions
add_definitions(-fprofile-arcs -ftest-coverage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Find required packages
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Set the sources
set(sources
                src/testRunner.cpp
                ../src/personFactory.cpp
                )

# Set Include directories
include_directories(
                src/
                ../src/
                )

# Create the executable
add_executable(TestFactory ${sources})

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/TestFactory.dir/src)
message("-- Object files will be output to: ${OBJECT_DIR}")

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")

add_library(commonLibrary ../src/personFactory.cpp)

add_executable(testRunner src/testRunner.cpp)
target_link_libraries(testRunner commonLibrary ${GTEST_LIBRARIES} pthread)
