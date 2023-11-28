cmake_minimum_required(VERSION  3.20)
project(r329_for_x64linux)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/socket/)


add_executable(io_write src/IO/io_write.c)
add_executable(io_read src/IO/io_read.c)
