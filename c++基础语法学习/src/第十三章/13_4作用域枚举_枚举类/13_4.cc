#include<iostream>
#include<utility> //for std::to_underlying(c++23)
//import std;


//防止污染命名空间

//作用域内枚举的工作方式与无作用域枚举类似，但有两个主要区别：
// 它们是强类型（它们不会隐式转换为整数）和强作用域（枚举器仅放置在枚举的作用域区域中）。
enum class Color
    {
        red,
        blue,
    };

constexpr auto operator+(Color a) noexcept
{
    return static_cast<std::underlying_type_t<Color>>(a);
}


constexpr std::string_view getColor(Color color)
{
    using enum Color;//避免在 switch 语句中使用多个冗余的明显前缀
    switch (color)
    {
    case red:
        return "red";
        break;
    case blue:
        return "blue";
    default:
        return "???";
        break;
    }
}

int main()
{
    //作用域枚举

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

    //也可以反过来将整数 转换为枚举类型
    int input{1};
    Color theColor{static_cast<Color>(input)};

    //老是用static_cast 显式转换很麻烦？
    // 可以采用如下隐式的方法转换：
    // 重载一元 operator+ 来转换

    std::cout << "使用一元重载符号 '+' : " << +Color::red << '\n';

    //或者使用 using enum (c++20)
    std::cout << "颜色是：" << getColor(theColor) << '\n';
    return 0;
}
