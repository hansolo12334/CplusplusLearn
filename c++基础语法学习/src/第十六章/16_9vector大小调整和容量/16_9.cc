#include <iostream>
#include <vector>
#include<string_view>



int main()
{
    std::vector vec{1, 23, 4, 5};
    //在运行时调整数组大小
    vec.resize(6); //默认新开辟的空间填充为 0

    for(auto v:vec){
        std::cout << v << '\n';
    }
    std::cout << "----------\n";

    vec.resize(2); //调整后比原来的小 则相当于切除
    for(auto v:vec){
        std::cout << v << '\n';
    }
    std::cout << "----------\n";
    vec.resize(4, 100); //也可以选择填充的内容 c++20
    for(auto v:vec){
        std::cout << v << '\n';
    }
    // vec.shrink_to_fit 调整数组容量来匹配其长度
    // 长度不是容量  容量是已经分配内存的元素数 长度是正在使用的元素数

    return 0;
}
