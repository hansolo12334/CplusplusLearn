#include<iostream>

//如果您确实发现了非常量全局变量的良好用途，那么一些有用的建议将最大限度地减少您可能遇到的麻烦。此建议不仅适用于非常量全局变量，而且可以帮助处理所有全局变量

//首先，在所有非命名空间的全局变量前面加上“g”或“g_”，或者更好的是，将它们放在一个命名空间中（在第 7.2 课 - 用户定义的命名空间和作用域解析运算符中讨论），以减少命名冲突的机会

[[maybe_unused]]constexpr double gravity{9.8};

//使用如下代替
namespace constants
{
    constexpr double gravity{9.8};
}

//其次，与其允许直接访问全局变量，不如“封装”变量。确保变量只能从声明它的文件中访问，例如，通过使变量成为静态或常量，然后提供外部全局“访问函数”来处理变量。这些功能可以确保保持正确的使用（例如，进行输入验证，范围检查等）。此外，如果您决定更改底层实现（例如，从一个数据库移动到另一个数据库），则只需更新访问函数，而不是直接使用全局变量的每段代码

//第三，在编写使用全局变量的独立函数时，不要直接在函数体中使用该变量。改为将其作为参数传入。这样，如果您的函数在某些情况下需要使用不同的值，您可以简单地改变参数。这有助于保持模块化

double getGravity()
{
    return constants::gravity;
}

double instantVelocity(int time,double gravity)
{
    return gravity * time;
}

int main()
{
    //将我们的常数作为参数传入
    std::cout << instantVelocity(5,constants::gravity) << '\n';

    return 0;
}
