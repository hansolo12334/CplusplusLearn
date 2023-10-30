#include<iostream>
#include<Fraction.h>

//不要忘记用分号结束类型定义，否则编译器通常会在下一行代码中出错。

//命名程序定义的类型：程序定义的类型以大写字母开头命名，不要使用后缀

//类型定义部分不受单一定义规则 （ODR，one definition rule） 的约束

// struct Fraction
// {
//     int cat{};
//     int dog{};
// };


int main()
{
    Fraction fraction{3,4};
    std::cout << fraction.cow << '\n';
    return 0;
}
