cmake_minimum_required(VERSION  3.20)


set(CMAKE_SYSTEM_PROCESSOR arm)
set(SYSTEM_NAME linux)
set(CMAKE_C_COMPILER " aarch64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER " aarch64-linux-gnu-g++")

project(hello_world)



add_executable(test ${PROJECT_SOURCE_DIR}/src/test/test.cpp)
add_executable(test_leds ${PROJECT_SOURCE_DIR}/src/leds/test_leds.cpp)
add_executable(test_lcd ${PROJECT_SOURCE_DIR}/src/lcd/test_lcd.cpp)
add_executable(lcd1 ${PROJECT_SOURCE_DIR}/src/lcd/lcd1.cpp)


include_directories(${PROJECT_SOURCE_DIR}/src/lcd/include)

add_executable(lcd2 ${PROJECT_SOURCE_DIR}/src/lcd/test.cpp
                    ${PROJECT_SOURCE_DIR}/src/lcd/lcd.cpp                 )
