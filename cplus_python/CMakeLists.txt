cmake_minimum_required(VERSION 2.20)
project(cplus_python)


find_package(Eigen3 REQUIRED )
find_package(Python3 COMPONENTS Development NumPy)

include_directories( ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})



add_executable(test src/c++python混合编程/test.cc)
target_link_libraries(test Python3::Python Python3::NumPy Eigen3::Eigen)

add_executable(test_input src/c++python混合编程/test_input.cc)
target_link_libraries(test_input Python3::Python Python3::NumPy Eigen3::Eigen)

add_executable(test_input2 src/c++python混合编程/test_input2.cc)
target_link_libraries(test_input2 Python3::Python Python3::NumPy Eigen3::Eigen)
