#include<iostream>


//函数重载
//实现多中返回类型的add?

int add(int x,int y)
{
    return x + y;
}

double add(double x,double y)
{
    return x + y;
}

// 这样是可行的！
// 上面的程序将编译。尽管您可能希望这些函数会导致命名冲突，但此处并非如此。
// 由于这些函数的参数类型不同，因此编译器能够区分这些函数，并将它们视为恰好共享名称的单独函数

int main()
{
    std::cout << add(1, 2) << '\n';
    std::cout << add(1.2, 1.3) << '\n';

    return 0;
}
