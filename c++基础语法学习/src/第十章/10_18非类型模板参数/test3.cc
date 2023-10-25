#include <iostream>

// write your mult function template here
// Q: 编写一个名为 mult 的函数模板，允许用户将任何类型的一个值（第一个参数）和一个整数（第二个参数）相乘。该函数应返回与第一个参数相同的类型。应运行以下程序：
auto mult(auto x, auto y)
{
    return x * y;
}

template<typename T>
T mult1(T x,int y)
{
    return x * y;
}


//Q: 编写一个名为 sub 的函数模板，允许用户减去两个不同类型的值。应运行以下程序：

auto sub(auto x,auto y)
{
    return x - y;
}

template<typename T,typename U>
auto sub1(T x,U y)
{
    return x - y;
}


int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult1(1.2, 3) << '\n';


    std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

    std::cout << sub1(3, 2) << '\n';
	std::cout << sub1(3.5, 2) << '\n';
	std::cout << sub1(4, 1.5) << '\n';


	return 0;
}
