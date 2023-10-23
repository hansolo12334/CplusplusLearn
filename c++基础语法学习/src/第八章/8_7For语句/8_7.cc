#include<iostream>

//避免在 operator!= for 循环条件下进行数值比较
int main()
{
    // 对于具有多个计数器的循环
    //这是C++中唯一在同一语句中定义多个变量的地方，并且使用逗号运算符被认为是可接受的做法。
    for (size_t x{0}, y{9}; x < 10; ++x,--y)
    {
        std::cout << x << ' ' << y << '\n';
    }

    return 0;
}
