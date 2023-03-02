# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

project(03_Prototype)

set(SOURCES src/main.cpp
            src/Address.cpp
            src/Contact.cpp
            src/ContactFactory.cpp)

add_subdirectory(tests)
find_package(Boost 1.70.0 REQUIRED system serialization)
add_executable(03_Prototype ${SOURCES})
target_link_libraries(03_Prototype PRIVATE Boost::headers Boost::system Boost::serialization)
