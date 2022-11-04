# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

project(01_Builder_Facets)

add_subdirectory(libraries/myLibrary)

add_executable(01_Builder_Facets src/main.cpp)
target_link_libraries(01_Builder_Facets PUBLIC myLibrary)
