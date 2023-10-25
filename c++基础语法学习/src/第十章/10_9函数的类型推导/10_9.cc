#include<iostream>



auto add(int x,int y)
{
    return x + y;
}

/*
auto judge(bool b)
{
    if(b)
    {
        return 5;
    }
    else
    {
        return 4.5; //auto 必须返回同一种类型
    } //error: inconsistent deduction for auto return type: ‘int’ and then ‘double’
}
*/
//使用 auto 返回类型的函数的一个主要缺点是，必须先完全定义此类函数，然后才能使用它们（前向声明是不够的）

//尾随返回语法
auto divide(double x, double y) -> double
{
    return x / y;
}


// 类型推断不能用于函数参数类型
// 但是由于编译器版本大于C++20，所以没报错
// 在 C++20 中， auto 关键字被扩展，以便上述程序将正确编译和运行
// 但是， auto 在这种情况下不调用类型推导。
// 相反，它正在触发一种称为 函数模板（function templates）实际处理 此类情况的不同功能
void printAdd(auto x,auto y)
{
    std::cout << x + y << '\n';
}

        //    |
        //    |
        //    |
        //   \/

//函数模板（function templates）
template <typename T>
void printAddd(T x,T y)
{
     std::cout << x + y << '\n';
}


int main()
{
    std::cout << divide(1, 2) << '\n';
    printAdd(1, 2.3);
    printAddd(1, 2);
    return 0;
}
