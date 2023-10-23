#include<iostream>
//前向声明

int g_x{2}; //non-constant globals
extern const int g_y{3};//constant globals

//虽然 constexpr 变量可以通过 extern 关键字给出外部链接，但它们不能被前向声明，因此给它们外部链接没有任何价值
extern constexpr int g_z{5};

void func()
{
    std::cout << "来自外部的函数\n";
}
//
