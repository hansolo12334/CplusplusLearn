##1. cmake基础学习 预处理器 指令 宏定义 标头保护学习 20230901
cmake_minimum_required(VERSION 3.16)
project(CppPorject)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${PROJECT_SOURCE_DIR}/include)


#生成动态库.so
# add_library(LibDosomething
#             SHARED
#             src/dosomething.cpp)

#生成静态库.a
add_library(Dosomething
            STATIC
            ${PROJECT_SOURCE_DIR}/src/dosomething.cpp)

add_executable(hello ${PROJECT_SOURCE_DIR}/src/hello.cc)



#直接调用dosomething.cpp
#add_executable(test1 src/test1.cc src/dosomething.cpp)



#调用add_library编译得到的静态库或动态库LibDosomething文件
#但是动态库在加载时需要寻找需要的库文件 例如如果dosomething.cpp .h 不见了 则编译失败
#而静态库不会 但是静态库会比较庞大
link_directories(${PROJECT_SOURCE_DIR}/include)
#link_libraries(Dosomething)

add_executable(2_10 ${PROJECT_SOURCE_DIR}/src/2_10预处理器/2_10.cc)
target_link_libraries(2_10 Dosomething)

add_executable(test_size ${PROJECT_SOURCE_DIR}/src/test_size.cc)
add_executable(test_symbol ${PROJECT_SOURCE_DIR}/src/4_4符号/test_symbol.cc)
add_executable(test_symbol1 ${PROJECT_SOURCE_DIR}/src/4_4符号/test_symbol1.cc)
add_executable(4_11 ${PROJECT_SOURCE_DIR}/src/4_11字符/4_11.cc)
add_executable(4_12 ${PROJECT_SOURCE_DIR}/src/4_12类型转换和static_cast简介/4_12.cc)
add_executable(4_13 ${PROJECT_SOURCE_DIR}/src/4_13const变量和符号常量/4_13.cc)
add_executable(4_14 ${PROJECT_SOURCE_DIR}/src/4_14编译时常量_常量表达式和constexpr/4_14.cc)
