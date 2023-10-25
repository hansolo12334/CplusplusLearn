#include<iostream>

#include <cassert>
#include <cmath> // for std::sqrt


//非类型模板参数
//非类型模板参数是具有固定类型的模板参数，用作作为模板参数传入的 constexpr 值的占位符
//非类型模板参数可以是以下任何类型：
// integral type 整型、
// std::nullptr_t
// enumeration type 枚举类型
// float point type 浮点类型 （自 C++20 起）
// pointer or reference to a object 指向对象的指针或引用
// pointer or reference to a function 对函数的指针或引用
// pointer or reference to a member function 对成员函数的指针或引用
// A literal class type 文本类类型（自 C++20 起）


//用 int 非类型模板参数的函数:
//？？？？
template<int N> //声明一个名为 N 的 int 类型的非类型模板参数
void print()
{
    std::cout << N << '\n';
}

/*
实际上编译器把调用转化为了如下:
template <>
void print<5>()
{
    std::cout << 5 << '\n';
}
*/

// 这么复杂有什么用？
// 例如：
/*
运行时，调用 getSqrt(-5.0) 将运行时断言。
虽然这总比没有好，因为 -5.0 它是一个字面的（并且隐式的 constexpr），如果我们能static_assert，以便在编译时捕获这样的错误会更好。
但是，static_assert需要一个常量表达式，并且函数参数不能是constexpr...
*/


double getSqrt(double d)
{
    assert(d >= 0.0 && "getSqrt(): d 必须非负");

    //要是能static_assert就好了
    if (d >= 0)
        return std::sqrt(d);

    return 0.0;
}

/*
但是，如果我们将函数参数更改为非类型模板参数，那么我们可以完全按照我们的意愿进行操作：

此版本无法编译。当编译器遇到 getSqrt<-5.0>() 时，它将实例化并调用一个看起来像这样的函数
*/
template<double D>
double getSqrt_d()
{
    static_assert(D >= 0.0, "getSqrt(): d 必须非负");
    //static_assert需要常量表达式
    if constexpr(D >= 0)
    {
        return std::sqrt(D);
    }
    return 0.0;
}

//对于C++17

template<auto N> //auto : 让编译器从模板参数 自己去推断 非类型模板参数
void print_n()
{
    std::cout << N << '\n';
}

int main()
{
    print<5>();

    print<'c'>(); //输出 99 字符c隐式转换为ASCII码 99

    print_n<'c'>(); //输出c

    std::cout << getSqrt(5.0) << '\n';
    std::cout << getSqrt(-5.0) << '\n'; //运行时报错 断言

    std::cout << getSqrt_d< 5.0 >() << '\n';

    //std::cout << getSqrt_d< -5.0 >() << '\n';
    //编译时报错 断言！ error: static assertion failed: getSqrt(): d 必须非负

    return 0;
}
