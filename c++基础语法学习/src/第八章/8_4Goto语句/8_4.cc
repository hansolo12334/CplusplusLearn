#include<iostream>


//在C++中，无条件跳转是通过 goto 语句实现的，并且通过使用语句标签来标识要跳转到的位置。
//以下是 和 goto statement statement label 的示例：

// 跳转有两个主要限制：
// 只能在单个函数的范围内跳转（不能跳出一个函数并跳到另一个函数），
// 如果向前跳转，则不能向前跳转到位置仍在范围内的任何变量的初始化。

//不要使用goto 会导致程序混乱！！

int main()
{
    double x{};

tryAgain:
    std::cout << "输入一个正数:";
    std::cin >> x;

    if (x<0.0)
    {
        goto tryAgain;
    }

    std::cout << "这个数是 " << x << '\n';

//     goto skip;

//     int y{2};

// skip: //报错 可以向后跳过变量初始化，执行初始化时将重新初始化该变量。

//     y += 1;


    return 0;
}
