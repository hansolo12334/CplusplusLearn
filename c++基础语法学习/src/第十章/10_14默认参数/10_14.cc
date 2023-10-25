#include<iostream>


//一个函数可以有多个带有默认参数的参数：
void print(int x=9,int y=10)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

//何时使用默认参数

// int rollDie(int sides=6);
// void openLogFile(std::string filename="default.log");

//-----------------------------------------------------------------
// 不允许以下情况：
// void print(int x=10, int y);
// default argument given for parameter 1 of ‘void print(int, int)’
//如果多个参数具有默认参数，则最左侧的参数应该是最有可能由用户显式设置的参数

//-----------------------------------------------------------------
// 无法重新声明默认参数
/*
void print(int x, int y=4); // forward declaration

void print(int x, int y=4) // error: redefinition of default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
*/
// 不能这样！一旦声明后，无法重新声明默认参数（在同一文件中）。
// 这意味着对于具有前向声明和函数定义的函数，默认参数可以在前向声明或函数定义中声明，但不能同时声明两者。

//最佳做法是在前向声明中声明默认参数，而不是在函数定义中声明默认参数，因为前向声明更有可能被其他文件看到（特别是如果它在头文件中）。


int main()
{
    print(2, 3); //2 3
    print(2);    //2 10
    print();     // 9 10
    return 0;
}
