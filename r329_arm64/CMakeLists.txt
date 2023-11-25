cmake_minimum_required(VERSION  3.20)


set(CMAKE_SYSTEM_PROCESSOR arm)
set(SYSTEM_NAME linux)
set(CMAKE_C_COMPILER " aarch64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER " aarch64-linux-gnu-g++")

project(hello_world)



add_executable(test ${PROJECT_SOURCE_DIR}/src/test1/test.cpp)
add_executable(test_leds ${PROJECT_SOURCE_DIR}/src/test1/test_leds.cpp)
