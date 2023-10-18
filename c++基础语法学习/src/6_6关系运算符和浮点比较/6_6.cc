#include<iostream>

constexpr bool jjudgeEqual()
{
    return false;
}
constexpr bool judgeEqual() //constexpr 编译时常量
{
    return jjudgeEqual();
}

int main()
{

    //避免使用运算符 == 和运算符！= 来比较浮点值（如果有可能已计算这些值）
    //如果一个函数返回这样的文本（通常 0.0 或有时 1.0 ），则与相同类型的相同文本值进行直接比较是安全的：
    //if (someFcn() == 0.0) // okay if someFcn() returns 0.0 as a literal only
    // do something
    //或者，如果我们有一个可以保证是文字的 const 或 constexpr 浮点变量，那么进行直接比较是安全的
    //constexpr double gravity { 9.8 }
    //if (gravity == 9.8) // okay if gravity was initialized with a literal
    std::cout << judgeEqual() << '\n';
    return 0;
}
