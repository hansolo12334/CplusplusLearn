cmake_minimum_required(VERSION  3.20)
project(r329_arm64_cross_complie)
# set(CMAKE_FIND_ROOT_PATH  ${PROJECT_SOURCE_DIR}/tools)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(SYSTEM_NAME linux)
set(CMAKE_C_COMPILER "/usr/bin/aarch64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/aarch64-linux-gnu-g++")

# SET(CMAKE_FIND_ROOT_PATH  /home/hansolo/CplusplusLearn/r329_arm64/tools)





add_executable(test ${PROJECT_SOURCE_DIR}/src/test/test.cpp)
add_executable(test_leds ${PROJECT_SOURCE_DIR}/src/leds/test_leds.cpp)
add_executable(test_lcd ${PROJECT_SOURCE_DIR}/src/lcd/test_lcd.cpp)

add_executable(lcd1 ${PROJECT_SOURCE_DIR}/src/lcd/lcd1.cpp)




add_subdirectory(${PROJECT_SOURCE_DIR}/src/lcd_libs/)


add_subdirectory(${PROJECT_SOURCE_DIR}/src/lcd/)


add_subdirectory(${PROJECT_SOURCE_DIR}/src/socket/)



add_executable(test_button ${PROJECT_SOURCE_DIR}/src/buttons/test_button.c)
add_executable(test_button_pthread ${PROJECT_SOURCE_DIR}/src/buttons/test_button_pthread.c)
target_link_libraries(test_button_pthread pthread)

add_executable(test_memory ${PROJECT_SOURCE_DIR}/src/内存操作/test_memory.c)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/ffmpeg/)

add_executable(test_thread ${PROJECT_SOURCE_DIR}/src/线程/线程结束/test_thread.c)
target_link_libraries(test_thread pthread)


add_executable(test_thread1 ${PROJECT_SOURCE_DIR}/src/线程/线程回收/test.c)
target_link_libraries(test_thread1 pthread)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/线程/取消线程/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/线程/取消点/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/线程/分离线程/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/线程/注册线程清理函数/)
