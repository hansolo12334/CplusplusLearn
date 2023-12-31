cmake_minimum_required(VERSION  3.20)
project(taishanpai_cross_complie)

set(CMAKE_SYSTEM_PROCESSOR arm)
set(SYSTEM_NAME linux)
set(CMAKE_C_COMPILER "/usr/bin/aarch64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/aarch64-linux-gnu-g++")


# file(GLOB SRCS
#   "src/oled/wiringPi.h"
#   "src/oled/wiringPi.c"
#   "src/oled/wiringPiI2C.h"
#   "src/oled/wiringPiI2C.c" 
#   "src/oled/oled.c"
#   "src/oled/oled.h" 
#   "src/oled/font.h"
# )
file(GLOB SRCS
${PROJECT_SOURCE_DIR}/src/oled/src/wiringPi.c
${PROJECT_SOURCE_DIR}/src/oled/src/wiringPiI2C.c
${PROJECT_SOURCE_DIR}/src/oled/src/oled.c
)


# include_directories(${PROJECT_SOURCE_DIR}/src/oled/)

include_directories(${PROJECT_SOURCE_DIR}/src/oled/include)
add_executable(test1 ${PROJECT_SOURCE_DIR}/src/oled/test.c  ${SRCS} )
add_executable(test2 ${PROJECT_SOURCE_DIR}/src/oled/test2.c  ${SRCS} )

# add_executable(test2 ${PROJECT_SOURCE_DIR}/src/oled/test2.cpp 
# ${PROJECT_SOURCE_DIR}/src/oled/oled.c
# ${PROJECT_SOURCE_DIR}/src/oled/wiringPiI2C.c
# ${PROJECT_SOURCE_DIR}/src/oled/wiringPi.c )
target_link_libraries(test1 pthread rt )
target_link_libraries(test2 pthread rt )


add_executable(button_gpio_control ${PROJECT_SOURCE_DIR}/src/oled/button_gpio_control.c )
# 终端查看 iic端口
# sudo i2cdetect -y 2


add_subdirectory(${PROJECT_SOURCE_DIR}/src/oled_with_driver_at_fb0)