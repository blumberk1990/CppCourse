
# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(myLibrary)

# Add a library to this build. The name of the library is myLibrary and it
# consists of only the myLibrary.cpp file
add_library(myLibrary src/PersonBuilder.cpp 
                      src/PersonPersonalBuilder.cpp 
                      src/PersonAddressBuilder.cpp 
                      src/PersonEmploymentBuilder.cpp
                      ../../src/external/models/src/Person.cpp)
target_include_directories(myLibrary PUBLIC ../../src/external/ 
                                            src )
