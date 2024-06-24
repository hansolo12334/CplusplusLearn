cmake_minimum_required(VERSION 2.20)
project(test_gtest)

add_executable(test ./src/test.cc)

target_link_libraries(test gtest pthread)

add_test(test ${CMAKE_BINARY_DIR}/test)


add_executable(test2 ./src/test2.cc)

target_link_libraries(test2 gtest pthread)

add_test(test2 ${CMAKE_BINARY_DIR}/test)