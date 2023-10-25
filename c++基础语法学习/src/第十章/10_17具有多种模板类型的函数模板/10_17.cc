#include<iostream>


//多种类型的参数模板 并用auto 推断返回类型
template<typename T,typename V>
auto max(T x, V y)
{
    return (x < y) ? y : x;
}

//缩写函数模板
//对于c++20：可以这样：
auto min(auto x,auto y)
{
    return (x < y) ? x : y;
}

int main()
{
    std::cout << max(1.2, 3) << '\n';
    std::cout << min(1.2, 3) << '\n';
    return 0;
}
