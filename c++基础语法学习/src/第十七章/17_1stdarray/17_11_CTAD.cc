#include<array>
#include<iostream>



int main()
{
    //c++ 17的CTAD 类模板参数推导
    // 让编译器自己去推导元素的类型和长度
    constexpr std::array my_a{1, 2, 3};
    constexpr std::array my_b{1.224, 1.2433};


    //从c++20起 可以使用std::to_array 来帮助array的数组长度

    constexpr auto my_c{std::to_array<int>({1, 2, 3, 4})};
    constexpr auto my_c1{std::to_array({1, 2, 3, 4, 5})};

    for(const auto x:my_c)
    {
        std::cout << x << '\n';
    }
    return 0;
}
