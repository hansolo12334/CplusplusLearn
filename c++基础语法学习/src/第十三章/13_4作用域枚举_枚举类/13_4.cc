#include<iostream>
#include<utility> //for std::to_underlying(c++23)
//import std;


//防止污染命名空间

//作用域内枚举的工作方式与无作用域枚举类似，但有两个主要区别：
// 它们是强类型（它们不会隐式转换为整数）和强作用域（枚举器仅放置在枚举的作用域区域中）。

int main()
{
    //作用域枚举
    enum class Color
    {
        red,
        blue,
    };
    enum class Fruit
    {
        banana,
        apple,
    };

    Color color{Color::red};
    Fruit fruit{Fruit::banana};
    /*
    if (color==fruit) //编译错误 作用域内枚举不会转换为可与其他类型进行比较的任何类型
    {
        std::cout << "color == fruit\n";
    }
    else{
        std::cout << "color!=fruit\n";
    }
    */
    //std::cout << Color::blue  << '\n'; //报错
    //作用域内枚举不会隐式转换为整数

    //这样就行 用static_cast
    std::cout << static_cast<int>(Color::blue)  << '\n';
    //或者在c++23中使用 std::to_underlying()
    std::cout << std::to_underlying(color) << '\n';
    return 0;
}
