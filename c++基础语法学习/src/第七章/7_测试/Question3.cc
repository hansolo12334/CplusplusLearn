#include <iostream>

/*
编写一个函数 int accumulate(int x) 。此函数应返回已传递给此函数的所有值 x 的总和。
*/

int accumulate(int x)
{
    static int sum{0};
    sum += x;
    return sum;
}

int main()
{
    std::cout << accumulate(4) << '\n'; // prints 4
    std::cout << accumulate(3) << '\n'; // prints 7
    std::cout << accumulate(2) << '\n'; // prints 9
    std::cout << accumulate(1) << '\n'; // prints 10

    return 0;
}

/*
Q: 这个解决方案有什么缺点？
A: 如果不重新启动程序，则无法重置累积。
   无法运行多个累加器。
这两个缺点都可以使用仿函数 (重载括号运算符）而不是静态局部变量来解决。
*/
