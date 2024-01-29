cmake_minimum_required(VERSION 3.20)
project(thread_learn)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX )

add_subdirectory(src/第一章/)

add_subdirectory(src/第二章_线程管理/)


add_executable(test_yield src/test_yield.cc)
target_link_libraries(test_yield pthread)
