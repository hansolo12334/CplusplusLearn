#include<iostream>
#include <cstdarg> // 使用省略号需要这个库


//使用方法   return_type function_name(argument_list, ...)
//使用省略号的函数必须至少具有一个非省略号参数 传递给函数的任何参数都必须首先与argument_list参数匹配
int getValue(int count,...) // ... 相当于一个数组
{
    std::va_list list;
    va_start(list, count);
    for (int arg = 0; arg < count;arg++){
        std::cout << va_arg(list, int) << ' ';
    }
    va_end(list);
    std::cout << '\n';
    return 0;
}


//不适用省略号的原因: 输入没有类型检测 会出现意想不到的错误
//
int main()
{
    std::cout << getValue(2,3,5) << '\n';

    //不适用省略号的原因: 输入没有类型检测 会出现意想不到的错误
    std::cout << getValue(2, 3.0, 4) << '\n';//输出 4 -634465520
}
