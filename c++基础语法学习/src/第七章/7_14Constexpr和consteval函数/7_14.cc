#include<iostream>
#include<type_traits>

int greater(int x,int y)
{
    return (x > y ? x : y);
}

constexpr int greater1(int x,int y)
{
    if (std::is_constant_evaluated()) // if compile-time evaluation
        std::cout << "is_constant_evaluated\n";

    return (x > y ? x : y);
}

int main()
{
    using std::cout;

    constexpr int x{4};
    constexpr int y{5};
    cout << (x > y ? x : y) << " 更大!\n";
    /*
    使用constexpr 可以让编译器在编译时直接将(x > y ? x : y)转化为 5 ,
    所以这个表达式就不需要再运行时再计算一次，使程序运行更快
    */

   /*但是如果用函数来比较x y大小，如下所示
    程序就失去了在编译时评估代码的能力（这对性能不利）
    */
    cout << greater(x, y) << " 更大!\n";

    cout << greater1(x, y) << " 更大!\n";

    /*可以使用Constexpr函数在编译时进行评估*/


    //C++20 引入了关键字 consteval，该关键字用于指示函数必须在编译时求值，
    //否则将导致编译错误。此类函数称为即时函数

    return 0;
}
