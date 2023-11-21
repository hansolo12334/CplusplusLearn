#include<iostream>

//在多个文件中使用类模板
#include "pair.h"

void goo(); //对goo.cc中的goo()进行前向声明


//将Pair类重写为类模板
template<typename T>
struct Pair
{
    T first{};
    T second{};
};


template<typename T>
constexpr T max(Pair<T> p)
{
    return (p.first < p.second ? p.second : p.first);
}

//具有模板类型和非模板类型成员的类模板
template<typename T>
struct Foo
{
    T first{};
    int second{};
};

//具有多种模板类型的类模板
template<typename T,typename U>
struct Poo
{
    T first{};
    U second{};
};
template<typename T,typename U>
void print(Poo<T,U> p)
{
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

//使函数模板适用于多个类类型
template<typename T>
void print1(T p)
{
    std::cout << '[' << p.first << ", " << p.second << "]\n";
} //使其只有一个类型模板参数 该参数将匹配任何类型

//std库中本来就有一个pair的实现：
template<typename T,typename U>
void print3(std::pair<T,U> p)
{
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}


int main()
{
    Pair<int> p1{5, 6};


    Pair<double> p2{1.3, 1.4};

    std::cout << p1.first << ' ' << p1.second << '\n';
    std::cout << p2.first << ' ' << p2.second << '\n';

    std::cout << max(p1) << '\n';

    std::cout << max(p2) << '\n';

    Foo<std::string> f1{"hansolo", 2};

    std::cout << f1.first << ' ' << f1.second << '\n';

    Poo pp{3, "hansolo"};
    print(pp);

    print1(pp);


    std::pair<int, std::string> p4{23, "hansolo"};
    print3(p4);


    //在多个文件中使用类模板
    hansolo::pair<double> hansolo_pair{2.3, 2.5};
    std::cout << hansolo::max(hansolo_pair) << '\n';

    goo();

    return 0;
}
