#include <iostream>

//使用 using 进行别名
template<typename T>
struct Pair
{
    T first{};
    T second{};
};

template<typename T>
using Coord = Pair<T>;

template<typename T>
void printS(const Coord<T> &s)
{
    std::cout << s.first << ' ' << s.second << '\n';
}

int main()
{
    Coord ss{11, 22};//c++20不需要显式的定义模板类型 "<int>"就可以自动推导类型

    printS(ss);

    return 0;
}
