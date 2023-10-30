#include<iostream>

/*
编写一个名为该函数的函数，该 sort2 函数允许调用方传递 2 个 int 变量作为参数。当函数返回时，第一个参数应包含两个值中的较小值，第二个参数应包含两个值中的较大值。
以下代码应运行并打印注释中注明的值：
*/


void sort2(int &x,int &y)
{
    if(x>y)
    {
        int temp{x};
        x = y;
        y = temp;
    }
}

#include <iostream>

int main()
{
    int x { 7 };
    int y { 5 };

    sort2(x, y);
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y);
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return 0;
}
