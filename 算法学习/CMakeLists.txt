cmake_minimum_required(VERSION 3.20)
project(CppPorject)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

#SET(CMAKE_COLOR_MAKEFILE ON)

#include_directories(${PROJECT_SOURCE_DIR}/include)


find_package(GSL REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${GSL_INCLUDE_DIRES}
                    ${GSLCBLAS_INCLUDE_DIRS})

include_directories(${OPENCV_INCLUDE_DIRS})

add_executable(particle_filter ${PROJECT_SOURCE_DIR}/src/粒子滤波/main.cc)
target_link_libraries (particle_filter
                        ${GSL_LIBRARIES}
                        ${GSLBLAS_LIBRARIES}
                        ${OpenCV_LIBS})


add_subdirectory(${PROJECT_SOURCE_DIR}/src/Leecode/数据结构/数组/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/Leecode/数据结构/链表/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/Leecode/数据结构/字符串/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/Leecode/数据结构/队列/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/Leecode/数据结构/栈/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/Leecode/数据结构/树/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/Leecode/算法/排序/)
