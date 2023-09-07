#include<iostream>


int getValue()
{
    std::cout << "输入一个数字:\n";
    int y{};
    std::cin >> y;
    return y;
}

int main()
{
    //编译时常量
    const int x{3};                 //x是编译时常量
    const int y{4};                 //y是编译时常量
    const int z{x + y};             //x+y是编译时常量

    //运行时常量
    const int value{getValue()};    //value是运行时常量
    std::cout << "value: " << value << "\n";

    //我们通常希望尽可能使用编译时常量->更好的优化
    //编译时常量可以在常量表达式中使用，并允许更好的优化。
    //运行时常量只能在非常量表达式中使用。它们的主要用途是确保对象的值不被修改。
    //TODO: 关键字constexpr  constexpr 只能是编译时常量 如果初始化时为运行时常量会报错

    //constexpr int valuee{getValue()}; //valuee是运行时常量 报错： 表达式必须含有常量值C/C++(28) 4_14.cc(26, 25): 无法调用非 constexpr 函数 "getValue"
    constexpr int sum{4 + 5}; //sum是编译时常量 不报错

    //任何在初始化后不应修改且其初始值设定项在编译时 已知 的变量都应声明为constexpr
    //任何在初始化后不应修改且其初始值设定项在编译时 未知 的变量都应声明为const


    return 0;
}
