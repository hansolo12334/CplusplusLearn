#include<iostream>
#include<cmath>
#include<cassert>

int main()
{
    //c++中不包括执行幂运算的运算符 ^ ^在c++中有其他用途
    //要使用指数 用 std::pow()
    std::cout << std::pow(3, 4)<<'\n';
    int a{3};
    int b{2};
    std::cout << a / b << '\n';
    std::cout << static_cast<double>(a)/ b << '\n';
    std::cout << a / static_cast<double>(b) << '\n';
    std::cout << "Enter a number:";
    double c{};
    std::cin >> c;
    std::cout << "2/" << c << '=' << 2 / c << '\n'; // 2/0=inf
    assert(10<3);//assert 条件不满足则终止运行 报错 Assertion xxx failed
    return 0;
}
