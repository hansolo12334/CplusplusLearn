#include<iostream>


//C++17 引入了 constexpr if 语句，它要求条件是常量表达式。
//constexpr-if-语句的条件将在编译时被计算。

//当条件是常量表达式时，优先使用 constexpr if 语句而不是非 constexpr if 语句。



int main()
{
    constexpr double gravity{9.8};

    if constexpr (gravity==9.8) //这里始终为 true 所以编译时就被替换为了true
    {
        std::cout << "Gravity is normal\n";
    }
    else
    {
        std::cout << "not on earth!\n";
    }
    return 0;
}
