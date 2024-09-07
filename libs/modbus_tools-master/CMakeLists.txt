cmake_minimum_required(VERSION 3.20)
project(modbus_test)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(TARGET modbus_test)

include_directories(3rd)
include_directories(inc)

add_subdirectory(3rd)
add_subdirectory(src)