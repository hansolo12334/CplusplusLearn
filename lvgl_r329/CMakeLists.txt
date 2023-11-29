cmake_minimum_required(VERSION 3.1)

project(lvgl_fb)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(SYSTEM_NAME linux)
set(CMAKE_C_COMPILER "/usr/bin/aarch64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/aarch64-linux-gnu-g++")


include_directories(.)
add_subdirectory(lvgl)
add_subdirectory(lv_drivers)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/project/demo/main.c mouse_cursor_icon.c lv_port_indev_hansolo.c)
target_link_libraries(${PROJECT_NAME} PRIVATE lvgl lvgl::examples lvgl::demos lvgl::drivers pthread)
