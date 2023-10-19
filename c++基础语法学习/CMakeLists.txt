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

message("编译test_size")
add_executable(test_size ${PROJECT_SOURCE_DIR}/src/test_size.cc)

message("编译4_4符号test_symbol")
add_executable(test_symbol ${PROJECT_SOURCE_DIR}/src/4_4符号/test_symbol.cc)

message("编译4_4符号test_symbol1")
add_executable(test_symbol1 ${PROJECT_SOURCE_DIR}/src/4_4符号/test_symbol1.cc)

message("编译4_11字符")
add_executable(4_11 ${PROJECT_SOURCE_DIR}/src/4_11字符/4_11.cc)

message("编译4_12类型转换和static_cast简介")
add_executable(4_12 ${PROJECT_SOURCE_DIR}/src/4_12类型转换和static_cast简介/4_12.cc)

message("编译4_13const变量和符号常量")
add_executable(4_13 ${PROJECT_SOURCE_DIR}/src/4_13const变量和符号常量/4_13.cc)

message("编译4_14编译时常量_常量表达式和constexpr")
add_executable(4_14 ${PROJECT_SOURCE_DIR}/src/4_14编译时常量_常量表达式和constexpr/4_14.cc)

message("编译4_15文字")
add_executable(4_15 ${PROJECT_SOURCE_DIR}/src/4_15文字/4_15文字.cc)


message("编译4_16数字系统")
add_executable(4_16 ${PROJECT_SOURCE_DIR}/src/4_16数字系统/4_16数字系统.cc)

#新
#添加子目录 编译CMake
#message
message("使用子目录寻找CMakeLists")
add_subdirectory(${PROJECT_SOURCE_DIR}/src/4_17字符串string)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/4_18string_view)

message("编译4_测试")
add_executable(4_test1 ${PROJECT_SOURCE_DIR}/src/4_测试/4_测试1.cc)
add_executable(4_test2 ${PROJECT_SOURCE_DIR}/src/4_测试/4_测试2.cc)
add_executable(4_test3 ${PROJECT_SOURCE_DIR}/src/4_测试/4_测试3.cc)

message("编译6_1操作符优先级和关联性")
add_executable(6_1 ${PROJECT_SOURCE_DIR}/src/6_1操作符优先级和关联性/6_1.cc)
add_executable(6_11 ${PROJECT_SOURCE_DIR}/src/6_1操作符优先级和关联性/6_11.cc)

message("编译6_5逗号和条件运算符")
add_executable(6_5 ${PROJECT_SOURCE_DIR}/src/6_5逗号和条件运算符/6_5逗号和条件运算符.cc)

message("编译6_56_6关系运算符和浮点比较")
add_executable(6_6 ${PROJECT_SOURCE_DIR}/src/6_6关系运算符和浮点比较/6_6.cc)


##7_2
message("编译7_2")
#方式一 生成静态库.a 再调用静态库
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(Dosomething7_21
            STATIC
            ${PROJECT_SOURCE_DIR}/src/7_2用户定义命名空间和范围解析运算符/dosomething7_21.cc)

add_executable(7_2 ${PROJECT_SOURCE_DIR}/src/7_2用户定义命名空间和范围解析运算符/7_2.cc)
target_link_libraries(7_2 Dosomething7_21)

#方式二 直接调用头文件对应的cc
#add_executable(7_2 ${PROJECT_SOURCE_DIR}/src/7_2用户定义命名空间和范围解析运算符/7_2.cc src/7_2用户定义命名空间和范围解析运算符/dosomething7_21.cc)

message("编译7_3")
add_executable(7_3_test ${PROJECT_SOURCE_DIR}/src/7_3局部变量/7_3_test.cc)

message("编译7_4")
add_executable(7_4 ${PROJECT_SOURCE_DIR}/src/7_4全局变量/7_4.cc)

message("编译7_5")
add_executable(7_5 ${PROJECT_SOURCE_DIR}/src/7_5变量阴影_名称隐藏/7_5.cc)

message("编译7_6")
add_executable(7_6 ${PROJECT_SOURCE_DIR}/src/7_6内联/7_6.cc)

message("编译7_7")
add_executable(7_7 ${PROJECT_SOURCE_DIR}/src/7_7外部联系和可变前向声明/7_7.cc
                    src/7_7外部联系和可变前向声明/extern_fun.cc)



#add_executable(4_17 ${PROJECT_SOURCE_DIR}/src/4_17字符串string/4_17字符串string.cc)
