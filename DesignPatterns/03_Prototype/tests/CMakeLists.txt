# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")
#set(GMOCK_LIBRARIES /usr/lib/libgmock.a /usr/lib/libgmock_main.a)

add_library(commonLibrary   ../src/Address.cpp
                            ../src/Contact.cpp
                            ../src/ContactFactory.cpp)


find_package(Boost 1.70.0 REQUIRED system serialization)

add_executable(testRunner src/testRunner.cpp)

target_link_libraries(testRunner    commonLibrary 
                                    ${GTEST_LIBRARIES} 
                                    ${GMOCK_LIBRARIES}
                                    pthread
                             Boost::headers 
                                    Boost::system 
                                    Boost::serialization)

