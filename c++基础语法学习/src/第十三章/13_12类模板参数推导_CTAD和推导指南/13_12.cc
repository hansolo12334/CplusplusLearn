#include<iostream>

/*
类模板参数推导 （Class template argument deduction,CTAD） C++17
从 C++17 开始，当从类模板实例化对象时，编译器可以从对象初始值设定项的类型中推断模板类型（这称为类模板参数推导或简称 CTAD）
*/


namespace hansolo
{
    template<typename T,typename U>
    struct Pair
    {
        T first{};
        U second{};
    };

    //在C++17中需要增加如下的推导指引
    //使用T和U类型参数初始化时的Pair对象 应 推导为 Pair<T,U>
    template<typename T,typename U>
    Pair(T,U)->Pair<T,U>;
} // namespace hansolo

int main()
{
    hansolo::Pair<int,int> p1{1,2};
    std::cout<<p1.first<<' '<<p1.second<<'\n';

    hansolo::Pair p2{12,22}; //CTAD没报错
    //如果是c++17的话，没有声明模板参数 是会报错的 但这里是c++23


    std::cout<<p2.first<<' '<<p2.second<<'\n';

    return 0;

}
