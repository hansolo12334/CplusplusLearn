#include<iostream>
#include <cstdint>

void implicit_type_conversion(char x)
{
    std::cout << x << "\n";
}
int main()
{
    //隐式类型转换
    int x {60};
    implicit_type_conversion(x);            // 输出 <
    implicit_type_conversion(5.5);


    // 通过 static_cast 运算符进行显式类型转换
    // 新： c++中一般 < > 里是一种类型 这通常是 C++ 处理需要参数化类型的代码的方式
    double y{5.5};
    std::cout << static_cast<int>(y) << "\n"; //输出为 5  5.5被显式的转为5

    char ch1{97};
    std::cout << "ch1原本为:" << ch1 << "\n";
    std::cout << "ch1现在为:" << static_cast<int>(ch1) << "\n";

    int ch2{98};
    std::cout << "ch2原本为:" << ch2 << "\n";
    std::cout << "ch2现在为:" << static_cast<char>(ch2) << "\n";

    std::int8_t ch3{35};
    std::cout << "ch3原本为:" << ch3 << "\n"; //输出为字符 # 识别为了ASCII
    std::cout << "ch3原本为:" << static_cast<std::int16_t>(ch3) << "\n";//正确打出35
    std::cout << "ch3现在为:" << static_cast<char>(ch3) << "\n";//打出#
    std::cout << "ch3现在为:" << static_cast<int>(ch3) << "\n";//打出35


    return 0;
}
