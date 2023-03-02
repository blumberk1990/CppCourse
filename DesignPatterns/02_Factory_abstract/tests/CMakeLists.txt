# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")
#set(GMOCK_LIBRARIES /usr/lib/libgmock.a /usr/lib/libgmock_main.a)

add_library(commonLibrary ../src/Coffee.cpp
                          ../src/CoffeeFactory.cpp
                          ../src/DrinkFactory.cpp
                          ../src/Tea.cpp
                          ../src/TeaFactory.cpp)

add_executable(testRunner src/testRunner.cpp)
target_link_libraries(testRunner commonLibrary 
                                ${GTEST_LIBRARIES} 
                                ${GMOCK_LIBRARIES}
                                pthread)

