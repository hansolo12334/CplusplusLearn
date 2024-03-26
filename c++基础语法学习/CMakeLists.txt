##1. cmake基础学习 预处理器 指令 宏定义 标头保护学习 20230901
cmake_minimum_required(VERSION 3.25)
project(CppPorject)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

#SET(CMAKE_COLOR_MAKEFILE ON)

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

add_executable(2_10 ${PROJECT_SOURCE_DIR}/src/第二章/2_10预处理器/2_10.cc)
target_link_libraries(2_10 Dosomething)

message("编译test_size")
add_executable(test_size ${PROJECT_SOURCE_DIR}/src/test_size.cc)

message("编译4_4符号test_symbol")
add_executable(test_symbol ${PROJECT_SOURCE_DIR}/src/第四章/4_4符号/test_symbol.cc)

message("编译4_4符号test_symbol1")
add_executable(test_symbol1 ${PROJECT_SOURCE_DIR}/src/第四章/4_4符号/test_symbol1.cc)

message("编译4_11字符")
add_executable(4_11 ${PROJECT_SOURCE_DIR}/src/第四章/4_11字符/4_11.cc)

message("编译4_12类型转换和static_cast简介")
add_executable(4_12 ${PROJECT_SOURCE_DIR}/src/第四章/4_12类型转换和static_cast简介/4_12.cc)

message("编译4_13const变量和符号常量")
add_executable(4_13 ${PROJECT_SOURCE_DIR}/src/第四章/4_13const变量和符号常量/4_13.cc)

message("编译4_14编译时常量_常量表达式和constexpr")
add_executable(4_14 ${PROJECT_SOURCE_DIR}/src/第四章/4_14编译时常量_常量表达式和constexpr/4_14.cc)

message("编译4_15文字")
add_executable(4_15 ${PROJECT_SOURCE_DIR}/src/第四章/4_15文字/4_15文字.cc)


message("编译4_16数字系统")
add_executable(4_16 ${PROJECT_SOURCE_DIR}/src/第四章/4_16数字系统/4_16数字系统.cc)

#新
#添加子目录 编译CMake
#message
message("使用子目录寻找CMakeLists")
add_subdirectory(${PROJECT_SOURCE_DIR}/src/第四章/4_17字符串string)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/第四章/4_18string_view)

message("编译4_测试")
add_executable(4_test1 ${PROJECT_SOURCE_DIR}/src/第四章/4_测试/4_测试1.cc)
add_executable(4_test2 ${PROJECT_SOURCE_DIR}/src/第四章/4_测试/4_测试2.cc)
add_executable(4_test3 ${PROJECT_SOURCE_DIR}/src/第四章/4_测试/4_测试3.cc)

message("编译6_1操作符优先级和关联性")
add_executable(6_1 ${PROJECT_SOURCE_DIR}/src/第六章/6_1操作符优先级和关联性/6_1.cc)
add_executable(6_11 ${PROJECT_SOURCE_DIR}/src/第六章/6_1操作符优先级和关联性/6_11.cc)

message("编译6_5逗号和条件运算符")
add_executable(6_5 ${PROJECT_SOURCE_DIR}/src/第六章/6_5逗号和条件运算符/6_5逗号和条件运算符.cc)

message("编译6_56_6关系运算符和浮点比较")
add_executable(6_6 ${PROJECT_SOURCE_DIR}/src/第六章/6_6关系运算符和浮点比较/6_6.cc)


##7_2
message("编译7_2")
#方式一 生成静态库.a 再调用静态库
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(Dosomething7_21
            STATIC
            ${PROJECT_SOURCE_DIR}/src/第七章/7_2用户定义命名空间和范围解析运算符/dosomething7_21.cc)

add_executable(7_2 ${PROJECT_SOURCE_DIR}/src/第七章/7_2用户定义命名空间和范围解析运算符/7_2.cc)
target_link_libraries(7_2 Dosomething7_21)

#方式二 直接调用头文件对应的cc
#add_executable(7_2 ${PROJECT_SOURCE_DIR}/src/7_2用户定义命名空间和范围解析运算符/7_2.cc src/7_2用户定义命名空间和范围解析运算符/dosomething7_21.cc)

message("编译7_3")
add_executable(7_3_test ${PROJECT_SOURCE_DIR}/src/第七章/7_3局部变量/7_3_test.cc)

message("编译7_4")
add_executable(7_4 ${PROJECT_SOURCE_DIR}/src/第七章/7_4全局变量/7_4.cc)

message("编译7_5")
add_executable(7_5 ${PROJECT_SOURCE_DIR}/src/第七章/7_5变量阴影_名称隐藏/7_5.cc)

message("编译7_6")
add_executable(7_6 ${PROJECT_SOURCE_DIR}/src/第七章/7_6内联/7_6.cc)

message("编译7_7")
add_executable(7_7 ${PROJECT_SOURCE_DIR}/src/第七章/7_7外部联系和可变前向声明/7_7.cc
                    src/第七章/7_7外部联系和可变前向声明/extern_fun.cc)

message("编译7_71")
add_executable(7_71 ${PROJECT_SOURCE_DIR}/src/第七章/7_7外部联系和可变前向声明/7_71.cc)



message("编译7_92")
include_directories(${PROJECT_SOURCE_DIR}/include/7_9/c++17前)
add_executable(7_92
            ${PROJECT_SOURCE_DIR}/src/第七章/7_9在多个文件之间共享全局常量_使用内联变量/c++17前/7_92.cc
            src/第七章/7_9在多个文件之间共享全局常量_使用内联变量/c++17前/constants_before17_2.cc
                )

message("编译7_9")
include_directories(${PROJECT_SOURCE_DIR}/include/7_9/c++17)
add_executable(7_9
                ${PROJECT_SOURCE_DIR}/src/第七章/7_9在多个文件之间共享全局常量_使用内联变量/c++17/7_9.cc
                )



message("编译7_10")
add_executable(7_10
                ${PROJECT_SOURCE_DIR}/src/第七章/7_10静态局部变量/7_10.cc
                )

message("编译7_12")
add_executable(7_12
                ${PROJECT_SOURCE_DIR}/src/第七章/7_12使用声明和使用指令/7_12.cc
                )

message("编译7_13")
add_executable(7_13
                ${PROJECT_SOURCE_DIR}/src/第七章/7_13内联函数/7_13.cc
                )
message("编译7_14")
add_executable(7_14
                ${PROJECT_SOURCE_DIR}/src/第七章/7_14Constexpr和consteval函数/7_14.cc
                )

message("编译7_15")
add_executable(7_15
                ${PROJECT_SOURCE_DIR}/src/第七章/7_15未命名和内联命名空间/7_15.cc
                )
message("编译7_15_1")
add_executable(7_15_1
                ${PROJECT_SOURCE_DIR}/src/第七章/7_15未命名和内联命名空间/7_15_1.cc
                )


message("编译7_15_2")
add_executable(7_15_2
                ${PROJECT_SOURCE_DIR}/src/第七章/7_15未命名和内联命名空间/7_15_2.cc
                )

message("编译7_15_3")
add_executable(7_15_3
                ${PROJECT_SOURCE_DIR}/src/第七章/7_15未命名和内联命名空间/7_15_3.cc
                )
#add_executable(4_17 ${PROJECT_SOURCE_DIR}/src/4_17字符串string/4_17字符串string.cc)

message("编译7_test")
add_subdirectory(${PROJECT_SOURCE_DIR}/src/第七章/7_测试)


message("编译8_1")
add_executable(8_1
                ${PROJECT_SOURCE_DIR}/src/第八章/8_2if语句和块/8_1.cc
                )
message("编译8_3")

add_executable(8_3
                ${PROJECT_SOURCE_DIR}/src/第八章/8_3switch语句/8_3.cc
                )
target_compile_options(8_3 PUBLIC -W -Wall)

message("编译8_3_test")
add_executable(8_3_test
                ${PROJECT_SOURCE_DIR}/src/第八章/8_3switch语句/test.cc
                )

message("编译8_4")
add_executable(8_4
                ${PROJECT_SOURCE_DIR}/src/第八章/8_4Goto语句/8_4.cc
                )

message("编译8_5_test")
add_executable(8_5_test
                ${PROJECT_SOURCE_DIR}/src/第八章/8_5Loop和while/test.cc
                )

message("编译8_7")
add_executable(8_7
                ${PROJECT_SOURCE_DIR}/src/第八章/8_7For语句/8_7.cc
                )

message("编译8_9")
add_executable(8_9
                ${PROJECT_SOURCE_DIR}/src/第八章/8_9Halts提前退出程序/8_9.cc
                )

message("编译8_11")
add_executable(8_11
                ${PROJECT_SOURCE_DIR}/src/第八章/8_11Assert和static_assert/8_11.cc
                )
message("编译8_12")
add_executable(8_12 ${PROJECT_SOURCE_DIR}/src/第八章/8_12随机数生成/8_12.cc)

message("编译8_12_Mersenne_Twister")
add_executable(8_12_Mersenne_Twister ${PROJECT_SOURCE_DIR}/src/第八章/8_12随机数生成/8_12梅森旋转算法.cc)

message("编译8_12设置随机种子")
add_executable(8_12_random_seed ${PROJECT_SOURCE_DIR}/src/第八章/8_12随机数生成/8_12设置随机种子.cc)

message("编译8_测试")
add_executable(8_test ${PROJECT_SOURCE_DIR}/src/第八章/8_测试/8_test.cc)

message("编译8_测试")
include_directories(${PROJECT_SOURCE_DIR}/src/第八章/8_测试/include)
add_executable(8_test2 ${PROJECT_SOURCE_DIR}/src/第八章/8_测试/8_test2.cc)

message("编译10_1")
add_executable(10_1 ${PROJECT_SOURCE_DIR}/src/第十章/10_1隐式类型转换/10_1.cc)

message("编译10_2")
add_executable(10_2 ${PROJECT_SOURCE_DIR}/src/第十章/10_2浮点和integral_promotion/10_2.cc)

message("编译10_3")
add_executable(10_3 ${PROJECT_SOURCE_DIR}/src/第十章/10_3数值转换/10_3.cc)

message("编译10_5")
add_executable(10_5 ${PROJECT_SOURCE_DIR}/src/第十章/10_5显式类型转换/10_5.cc)

message("编译10_7")
add_executable(10_7 ${PROJECT_SOURCE_DIR}/src/第十章/10_7类型定义和类型别名/10_7.cc)

message("编译10_8")
add_executable(10_8 ${PROJECT_SOURCE_DIR}/src/第十章/10_8使用auto关键字为对象类型推导type_deduction/10_8.cc)

message("编译10_9")
add_executable(10_9 ${PROJECT_SOURCE_DIR}/src/第十章/10_9函数的类型推导/10_9.cc)

message("编译10_10")
add_executable(10_10 ${PROJECT_SOURCE_DIR}/src/第十章/10_10函数重载简介/10_10.cc)

message("编译10_11")
add_executable(10_11 ${PROJECT_SOURCE_DIR}/src/第十章/10_11函数重载区分/10_11.cc)

message("编译10_13")
add_executable(10_13 ${PROJECT_SOURCE_DIR}/src/第十章/10_13删除函数/10_13.cc)

message("编译10_14")
add_executable(10_14 ${PROJECT_SOURCE_DIR}/src/第十章/10_14默认参数/10_14.cc)

message("编译10_15")
add_executable(10_15 ${PROJECT_SOURCE_DIR}/src/第十章/10_15函数模板/10_15.cc)

message("编译10_16")
add_executable(10_16 ${PROJECT_SOURCE_DIR}/src/第十章/10_16函数模板实例化/10_16.cc)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/第十章/10_16函数模板实例化)

message("编译10_17")
add_executable(10_17 ${PROJECT_SOURCE_DIR}/src/第十章/10_17具有多种模板类型的函数模板/10_17.cc)

message("编译10_18")
add_executable(10_18 ${PROJECT_SOURCE_DIR}/src/第十章/10_18非类型模板参数/10_18.cc)

message("编译10_test")
add_executable(10_test ${PROJECT_SOURCE_DIR}/src/第十章/10_18非类型模板参数/test.cc)

message("编译10_test2")
add_executable(10_test2 ${PROJECT_SOURCE_DIR}/src/第十章/10_18非类型模板参数/test2.cc)

message("编译10_test3")
add_executable(10_test3 ${PROJECT_SOURCE_DIR}/src/第十章/10_18非类型模板参数/test3.cc)


message("编译12_test")
add_executable(12_test ${PROJECT_SOURCE_DIR}/src/第十二章/12_2值类别_左值和右值/test.cc)

message("编译12_7")
add_executable(12_7 ${PROJECT_SOURCE_DIR}/src/第十二章/12_7指针/12_7.cc)

message("编译12_7_dangling_pointer")
add_executable(12_7_dangling_pointer ${PROJECT_SOURCE_DIR}/src/第十二章/12_7指针/dangling_pointer.cc)

message("编译12_8")
add_executable(12_8 ${PROJECT_SOURCE_DIR}/src/第十二章/12_8空指针/12_8.cc)

message("编译12_9")
add_executable(12_9 ${PROJECT_SOURCE_DIR}/src/第十二章/12_9指针和常量/12_9.cc)

message("编译12_10")
add_executable(12_10 ${PROJECT_SOURCE_DIR}/src/第十二章/12_10按地址传递/12_10.cc)

message("编译12_12")
add_executable(12_12 ${PROJECT_SOURCE_DIR}/src/第十二章/12_12按引用返回和按地址返回/12_12.cc)

# message("编译12_14")
# add_executable(12_14 ${PROJECT_SOURCE_DIR}/src/第十二章/12_14使用指针_引用和常量进行类型推导/12_14.cc)

message("编译12_chapter_test")
add_executable(12_chapter_test ${PROJECT_SOURCE_DIR}/src/第十二章/12_test/12_test.cc)

message("编译13_1")
include_directories(${PROJECT_SOURCE_DIR}/src/第十三章/13_1程序定义_用户定义类型简介/include)
add_executable(13_1 ${PROJECT_SOURCE_DIR}/src/第十三章/13_1程序定义_用户定义类型简介/13_1程序定义_用户定义类型简介.cc)

message("编译13_2")
add_executable(13_2 ${PROJECT_SOURCE_DIR}/src/第十三章/13_2无作用域枚举/13_2.cc)

message("编译13_2_test")
add_executable(13_2_test ${PROJECT_SOURCE_DIR}/src/第十三章/13_2无作用域枚举/13_2test.cc)

message("编译13_3")
add_executable(13_3 ${PROJECT_SOURCE_DIR}/src/第十三章/13_3无作用域枚举的输入和输出/13_3.cc)

message("编译13_4")
add_executable(13_4 ${PROJECT_SOURCE_DIR}/src/第十三章/13_4作用域枚举_枚举类/13_4.cc)
#target_compile_features(13_4  PUBLIC cxx_std_23)

message("编译13_4_quiz")
add_executable(13_4_quiz ${PROJECT_SOURCE_DIR}/src/第十三章/13_4作用域枚举_枚举类/quiz.cc)

message("编译13_5")
add_executable(13_5 ${PROJECT_SOURCE_DIR}/src/第十三章/13_5结构体_成员和成员选择/13_5.cc)
# find_package(GSL REQUIRED)
# find_package(OpenCV REQUIRED)

# include_directories(${GSL_INCLUDE_DIRES}
#                     ${GSLCBLAS_INCLUDE_DIRS})

# include_directories(${OPENCV_INCLUDE_DIRS})

# add_executable(particle_filter ${PROJECT_SOURCE_DIR}/src/粒子滤波/main.cc)
# t                         ${GSL_LIBRARIES}
#                         ${GSLBLAS_LIBRARIES}
#                         ${OpenCV_LIBS})

 # include_directories("${Simbody_INCLUDE_DIR}")
# add_executable(sim ${PROJECT_SOURCE_DIR}/src/第十三章/13_4作用域枚举_枚举类/sim.cc)
message("编译13_7")
add_executable(13_7 ${PROJECT_SOURCE_DIR}/src/第十三章/13_7结构体默认成员初始化/13_7.cc)

message("编译13_8")
add_executable(13_8 ${PROJECT_SOURCE_DIR}/src/第十三章/13_8结构体传递和返回结构/13_8.cc)


message("编译13_8_quiz")
add_executable(13_8_quiz ${PROJECT_SOURCE_DIR}/src/第十三章/13_8结构体传递和返回结构/13_8_quiz.cc)

message("编译13_8_quiz2")
add_executable(13_8_quiz2 ${PROJECT_SOURCE_DIR}/src/第十三章/13_8结构体传递和返回结构/13_8quiz2.cc)

message("编译13_9")
add_executable(13_9 ${PROJECT_SOURCE_DIR}/src/第十三章/13_9结构体杂项/13_9.cc)

message("编译13_10")
add_executable(13_10 ${PROJECT_SOURCE_DIR}/src/第十三章/13_10使用指针和引用选择成员/13_10.cc)

message("编译13_11")
include_directories(${PROJECT_SOURCE_DIR}/src/第十三章/13_11类模板/include/)
add_executable(13_11
    ${PROJECT_SOURCE_DIR}/src/第十三章/13_11类模板/13_11.cc
    ${PROJECT_SOURCE_DIR}/src/第十三章/13_11类模板/goo.cc
)

message("编译13_12")
add_executable(13_12 ${PROJECT_SOURCE_DIR}/src/第十三章/13_12类模板参数推导_CTAD和推导指南/13_12.cc)

message("编译13_13")
add_executable(13_13 ${PROJECT_SOURCE_DIR}/src/第十三章/13_13别名模板/13_13.cc)

message("编译13_quiz")
add_executable(13_quiz ${PROJECT_SOURCE_DIR}/src/第十三章/13_quiz/13_quiz.cc)
add_executable(13_quiz2 ${PROJECT_SOURCE_DIR}/src/第十三章/13_quiz/13_quiz2.cc)


message("编译14_2")
add_executable(14_2 ${PROJECT_SOURCE_DIR}/src/第十四章/14_2类简介/14_2.cc)

message("编译14_3")
add_executable(14_3 ${PROJECT_SOURCE_DIR}/src/第十四章/14_3成员函数/14_3.cc)

message("编译14_3quiz")
add_executable(14_3quiz ${PROJECT_SOURCE_DIR}/src/第十四章/14_3成员函数/14_3quiz.cc)

message("编译14_4_1")
add_executable(14_4_1 ${PROJECT_SOURCE_DIR}/src/第十四章/14_4const类对象和const成员函数/14_4_1.cc)


message("编译14_4_2")
add_executable(14_4_2 ${PROJECT_SOURCE_DIR}/src/第十四章/14_4const类对象和const成员函数/14_4_2.cc)


message("编译14_5")
add_executable(14_5 ${PROJECT_SOURCE_DIR}/src/第十四章/14_5公有和私有成员以及访问限定符/14_5.cc)

message("编译14_5quiz")
add_executable(14_5quiz ${PROJECT_SOURCE_DIR}/src/第十四章/14_5公有和私有成员以及访问限定符/14_5quiz.cc)

message("编译14_6")
add_executable(14_6 ${PROJECT_SOURCE_DIR}/src/第十四章/14_6访问函数/14_6.cc)

message("编译14_7")
add_executable(14_7 ${PROJECT_SOURCE_DIR}/src/第十四章/14_7返回对数据成员的引用的成员函数/14_7.cc)

message("编译14_9")
add_executable(14_9 ${PROJECT_SOURCE_DIR}/src/第十四章/14_9构造函数简介/14_9.cc)

message("编译14_10")
add_executable(14_10 ${PROJECT_SOURCE_DIR}/src/第十四章/14_10构造函数成员初始值设定列表/14_10.cc)

message("编译14_10quiz")
add_executable(14_10quiz ${PROJECT_SOURCE_DIR}/src/第十四章/14_10构造函数成员初始值设定列表/14_10quiz.cc)

message("编译14_11")
add_executable(14_11 ${PROJECT_SOURCE_DIR}/src/第十四章/14_11默认构造函数和默认参数/14_11.cc)

message("编译14_12")
add_executable(14_12 ${PROJECT_SOURCE_DIR}/src/第十四章/14_12委派构造函数/14_12.cc)

message("编译14_12quiz")
add_executable(14_12quiz ${PROJECT_SOURCE_DIR}/src/第十四章/14_12委派构造函数/14_12quiz.cc)

message("编译14_13")
add_executable(14_13 ${PROJECT_SOURCE_DIR}/src/第十四章/14_13临时类对象/14_13.cc)

message("编译14_14")
add_executable(14_14 ${PROJECT_SOURCE_DIR}/src/第十四章/14_14复制构造函数/14_14.cc)


message("编译14_16")
add_executable(14_16 ${PROJECT_SOURCE_DIR}/src/第十四章/14_16转换构造函数和显式关键字/14_16.cc)

message("编译14quiz")
add_executable(14quiz ${PROJECT_SOURCE_DIR}/src/第十四章/14总结quiz/14quiz.cc)

message("编译14quiz1")
add_executable(14quiz1 ${PROJECT_SOURCE_DIR}/src/第十四章/14总结quiz/14quiz1.cc)

message("编译15_1")
add_executable(15_1 ${PROJECT_SOURCE_DIR}/src/第十五章/15_1隐藏的this指针和成员函数链接/15_1.cc)

message("编译15_2")
add_executable(15_2 ${PROJECT_SOURCE_DIR}/src/第十五章/15_2类和头文件/15_2.cc)
target_link_libraries(15_2 ${PROJECT_SOURCE_DIR}/src/第十五章/15_2类和头文件/Date.cc)


message("编译15_3")
add_executable(15_3 ${PROJECT_SOURCE_DIR}/src/第十五章/15_3嵌套类型/15_3.cc)

message("编译15_4")
add_executable(15_4 ${PROJECT_SOURCE_DIR}/src/第十五章/15_4析构函数/15_4.cc)

message("编译15_5")
add_executable(15_5 ${PROJECT_SOURCE_DIR}/src/第十五章/15_5具有成员函数的类模板/15_5.cc)


message("编译15_5quiz")
add_executable(15_5quiz ${PROJECT_SOURCE_DIR}/src/第十五章/15_5具有成员函数的类模板/15_5quiz.cc)

message("编译15_6")
add_executable(15_6 ${PROJECT_SOURCE_DIR}/src/第十五章/15_6静态成员变量/15_6.cc)

message("编译15_6example")
add_executable(15_6example ${PROJECT_SOURCE_DIR}/src/第十五章/15_6静态成员变量/15_6example.cc)

message("编译15_7")
add_executable(15_7 ${PROJECT_SOURCE_DIR}/src/第十五章/15_7静态成员函数/15_7.cc)

message("编译15_7quiz")
add_executable(15_7quiz ${PROJECT_SOURCE_DIR}/src/第十五章/15_7静态成员函数/15_7quiz.cc)

message("编译15_8")
add_executable(15_8 ${PROJECT_SOURCE_DIR}/src/第十五章/15_8友好非成员函数/15_8.cc)

message("编译15_9")
add_executable(15_9 ${PROJECT_SOURCE_DIR}/src/第十五章/15_9友好类和友好成员函数/15_9.cc)

message("编译15_9quiz")
add_executable(15_9quiz ${PROJECT_SOURCE_DIR}/src/第十五章/15_9友好类和友好成员函数/15_9quiz.cc)


message("编译15_9quiz2")
include_directories(${PROJECT_SOURCE_DIR}/src/第十五章/15_9友好类和友好成员函数/quiz/)
add_executable(15_9quiz2
${PROJECT_SOURCE_DIR}/src/第十五章/15_9友好类和友好成员函数/quiz2/main.cc
${PROJECT_SOURCE_DIR}/src/第十五章/15_9友好类和友好成员函数/quiz2/Vector3d.cc
${PROJECT_SOURCE_DIR}/src/第十五章/15_9友好类和友好成员函数/quiz2/Point3d.cc)

message("编译15_10")
add_executable(15_10 ${PROJECT_SOURCE_DIR}/src/第十五章/15_10Ref限定符/15_10.cc)

message("编译15quiz")
add_executable(15quiz ${PROJECT_SOURCE_DIR}/src/第十五章/十五章quiz/quiz.cc)


message("编译16_1")
add_executable(16_1 ${PROJECT_SOURCE_DIR}/src/第十六章/16_1容器和数组/16_1.cc)

message("编译16_4")
add_executable(16_4 ${PROJECT_SOURCE_DIR}/src/第十六章/16_4传递和返回vector和语义移动/16_4.cc)


message("编译16_7")
add_executable(16_7 ${PROJECT_SOURCE_DIR}/src/第十六章/16_7基于范围的for循环/16_7.cc)

message("编译16_9")
add_executable(16_9 ${PROJECT_SOURCE_DIR}/src/第十六章/16_9vector大小调整和容量/16_9.cc)

message("编译16_10")
add_executable(16_10 ${PROJECT_SOURCE_DIR}/src/第十六章/16_10vector堆栈行为/16_10.cc)

message("编译17_1")
add_executable(17_1 ${PROJECT_SOURCE_DIR}/src/第十七章/17_1stdarray/17_1.cc)
message("编译17_11_CTAD")
add_executable(17_11_CTAD ${PROJECT_SOURCE_DIR}/src/第十七章/17_1stdarray/17_11_CTAD.cc)

message("编译18_2")
add_executable(18_2 ${PROJECT_SOURCE_DIR}/src/第十八章/18_2迭代器/18_2.cc)

message("编译18_3")
add_executable(18_3 ${PROJECT_SOURCE_DIR}/src/第十八章/18_3标准算法库/18_3.cc)

message("编译18_4")
add_executable(18_4 ${PROJECT_SOURCE_DIR}/src/第十八章/18_4为代码计时/18_4.cc)

message("编译19_1")
add_executable(19_1 ${PROJECT_SOURCE_DIR}/src/第十九章/19_1使用新建和删除进行动态内存分配/19_1.cc)

message("编译19_2")
add_executable(19_2 ${PROJECT_SOURCE_DIR}/src/第十九章/19_2动态分配数组/19_2.cc)

message("编译19_2quiz")
add_executable(19_2quiz ${PROJECT_SOURCE_DIR}/src/第十九章/19_2动态分配数组/19_2quiz.cc)

message("编译19_5")
add_executable(19_5 ${PROJECT_SOURCE_DIR}/src/第十九章/19_5void指针/19_5.cc)

message("编译20_1")
add_executable(20_1 ${PROJECT_SOURCE_DIR}/src/第二十章/20_1函数指针/20_1.cc)

message("编译20_1_use_functional")
add_executable(20_1_use_functional ${PROJECT_SOURCE_DIR}/src/第二十章/20_1函数指针/20_1_use_functional.cc)


message("编译20_1quiz.cc")
add_executable(20_1quiz.cc ${PROJECT_SOURCE_DIR}/src/第二十章/20_1函数指针/20_1quiz.cc)

message("编译20_2.cc")
add_executable(20_2 ${PROJECT_SOURCE_DIR}/src/第二十章/20_2栈和堆/20_2.cc)

message("编译20_3.cc")
add_executable(20_3 ${PROJECT_SOURCE_DIR}/src/第二十章/20_3递归/20_3.cc)

message("编译20_3quiz_factorial.cc")
add_executable(20_3quiz_factorial ${PROJECT_SOURCE_DIR}/src/第二十章/20_3递归/20_3quiz_factorial.cc)

message("编译20_3quiz_sum.cc")
add_executable(20_3quiz_sum ${PROJECT_SOURCE_DIR}/src/第二十章/20_3递归/20_3quiz_sum.cc)

message("编译20_3quiz_int2binary.cc")
add_executable(20_3quiz_int2binary ${PROJECT_SOURCE_DIR}/src/第二十章/20_3递归/20_3quiz_int2binary.cc)

message("编译20_4.cc")
add_executable(20_4 ${PROJECT_SOURCE_DIR}/src/第二十章/20_4命令行参数/20_4.cc)

message("编译20_5.cc")
add_executable(20_5 ${PROJECT_SOURCE_DIR}/src/第二十章/20_5省略号/20_5.cc)

message("编译20_6.cc")
add_executable(20_6 ${PROJECT_SOURCE_DIR}/src/第二十章/20_6匿名函数/20_6.cc)

message("编译20_6_2.cc")
add_executable(20_6_2 ${PROJECT_SOURCE_DIR}/src/第二十章/20_6匿名函数/20_6_2.cc)

message("编译20_6_quiz.cc")
add_executable(20_6_quiz ${PROJECT_SOURCE_DIR}/src/第二十章/20_6匿名函数/20_6quiz.cc)

message("编译20_6_quiz2.cc")
add_executable(20_6_quiz2 ${PROJECT_SOURCE_DIR}/src/第二十章/20_6匿名函数/20_6quiz2.cc)

message("编译20_7.cc")
add_executable(20_7 ${PROJECT_SOURCE_DIR}/src/第二十章/20_7lambda捕获/20_7.cc)

message("编译20_7_2.cc")
add_executable(20_7_2 ${PROJECT_SOURCE_DIR}/src/第二十章/20_7lambda捕获/20_7_2.cc)

message("编译20_7_quiz.cc")
add_executable(20_7_quiz ${PROJECT_SOURCE_DIR}/src/第二十章/20_7lambda捕获/20_7_quiz.cc)



message("编译20quiz.cc")
add_executable(20quiz ${PROJECT_SOURCE_DIR}/src/第二十章/quiz/20quiz.cc)


message("编译22_1.cc")
add_executable(22_1 ${PROJECT_SOURCE_DIR}/src/第二十二章/22_1智能指针和移动语义/22_1.cc)

message("编译22_2.cc")
add_executable(22_2 ${PROJECT_SOURCE_DIR}/src/第二十二章/22_2移动构造函数和移动赋值/22_2.cc)

message("编译22_4.cc")
add_executable(22_3 ${PROJECT_SOURCE_DIR}/src/第二十二章/22_3std_move/22_3.cc)

message("编译22_5.cc")
add_executable(22_5 ${PROJECT_SOURCE_DIR}/src/第二十二章/22_5std_unique_ptr/22_5.cc)

message("编译22_5quiz.cc")
add_executable(22_5quiz ${PROJECT_SOURCE_DIR}/src/第二十二章/22_5std_unique_ptr/22_5quiz.cc)

message("编译22_6.cc")
add_executable(22_6 ${PROJECT_SOURCE_DIR}/src/第二十二章/22_6std_shared_ptr/22_6.cc)

message("编译22_7.cc")
add_executable(22_7 ${PROJECT_SOURCE_DIR}/src/第二十二章/22_7std_shared_ptr和std_weak_ptr的循环依赖问题/22_7.cc)

message("编译22_7_2.cc")
add_executable(22_7_2 ${PROJECT_SOURCE_DIR}/src/第二十二章/22_7std_shared_ptr和std_weak_ptr的循环依赖问题/22_7_2.cc)

message("编译22_7weak_ptr.cc")
add_executable(22_7weak_ptr ${PROJECT_SOURCE_DIR}/src/第二十二章/22_7std_shared_ptr和std_weak_ptr的循环依赖问题/22_7weak_ptr.cc)

message("编译22_7weak_ptr2.cc")
add_executable(22_7weak_ptr2 ${PROJECT_SOURCE_DIR}/src/第二十二章/22_7std_shared_ptr和std_weak_ptr的循环依赖问题/22_7weak_ptr2.cc)

message("编译22_7quiz.cc")
add_executable(22_7quiz ${PROJECT_SOURCE_DIR}/src/第二十二章/22_7std_shared_ptr和std_weak_ptr的循环依赖问题/22_7quiz.cc)

message("编译23_3.cc")
add_executable(23_3 ${PROJECT_SOURCE_DIR}/src/第二十三章/23_3聚合/23_3.cc)

message("编译23_3quiz.cc")
add_executable(23_3quiz ${PROJECT_SOURCE_DIR}/src/第二十三章/23_3聚合/23_3quiz.cc)

message("编译23_6.cc")
add_executable(23_6 ${PROJECT_SOURCE_DIR}/src/第二十三章/23_6容器类/23_6.cc)

message("编译24_2.cc")
add_executable(24_2 ${PROJECT_SOURCE_DIR}/src/第二十四章/24_2C++的基本继承/24_2.cc)

message("编译24_3.cc")
add_executable(24_3 ${PROJECT_SOURCE_DIR}/src/第二十四章/24_3派生类的构造顺序/24_3.cc)

message("编译24_4.cc")
add_executable(24_4 ${PROJECT_SOURCE_DIR}/src/第二十四章/24_4派生类的构造函数和初始化/24_4.cc)

message("编译24_4quiz.cc")
add_executable(24_4quiz ${PROJECT_SOURCE_DIR}/src/第二十四章/24_4派生类的构造函数和初始化/24_4quiz.cc)

# message("编译24_5.cc")
# add_executable(24_5 ${PROJECT_SOURCE_DIR}/src/第二十四章/24_5继承和访问说明符/24_5.cc)

message("编译24_6.cc")
add_executable(24_6 ${PROJECT_SOURCE_DIR}/src/第二十四章/24_6向派生类添加新功能/24_6.cc)

message("编译24_7.cc")
add_executable(24_7 ${PROJECT_SOURCE_DIR}/src/第二十四章/24_7调用继承的函数和覆盖行为/24_7.cc)

message("编译24_8.cc")
add_executable(24_8 ${PROJECT_SOURCE_DIR}/src/第二十四章/24_8隐藏继承的功能/24_8.cc)

message("编译24_9.cc")
add_executable(24_9 ${PROJECT_SOURCE_DIR}/src/第二十四章/24_9多重继承/24_9.cc)

message("编译24_quiz.cc")
add_executable(24_quiz ${PROJECT_SOURCE_DIR}/src/第二十四章/24_quiz/24_quiz.cc)

message("编译24_quiz2.cc")
add_executable(24_quiz2 ${PROJECT_SOURCE_DIR}/src/第二十四章/24_quiz/24_quiz2.cc)

message("编译25_1.cc")
add_executable(25_1 ${PROJECT_SOURCE_DIR}/src/第二十五章/25_1指向派生对象的基类的指针和引用/25_1.cc)

message("编译25_2.cc")
add_executable(25_2 ${PROJECT_SOURCE_DIR}/src/第二十五章/25_2虚函数和多态性/25_2.cc)

message("编译25_2_test.cc")
add_executable(25_2_test ${PROJECT_SOURCE_DIR}/src/第二十五章/25_2虚函数和多态性/25_2_test.cc)

message("编译25_3.cc")
add_executable(25_3 ${PROJECT_SOURCE_DIR}/src/第二十五章/25_3覆盖和最终说明符以及协变返回类型/25_3.cc)
