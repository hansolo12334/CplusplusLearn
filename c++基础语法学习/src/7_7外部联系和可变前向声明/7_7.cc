#include<iostream>


//函数默认具有外部链接
void func();


//如果要定义未初始化的非 const 全局变量，请不要使用 extern 关键字，否则C++会认为您正在尝试为变量进行前向声明
extern int g_x;

extern const int g_y;

//全局变量的动态初始化会导致C++很多问题。尽可能避免动态初始化

int main()
{
    func();

    std::cout << g_y << '\n';
    std::cout << g_x+3 << '\n';
    return 0;
}

//如果您确实发现了非常量全局变量的良好用途，那么一些有用的建议将最大限度地减少您可能遇到的麻烦。此建议不仅适用于非常量全局变量，而且可以帮助处理所有全局变量

//首先，在所有非命名空间的全局变量前面加上“g”或“g_”，或者更好的是，将它们放在一个命名空间中（在第 7.2 课 - 用户定义的命名空间和作用域解析运算符中讨论），以减少命名冲突的机会
