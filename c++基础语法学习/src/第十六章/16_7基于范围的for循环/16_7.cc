#include <iostream>
#include <vector>
#include<string_view>


#include<ranges> //c++ 20
//c++20 提供了反向遍历元素的方法




int main()
{
    using namespace std::literals;

    std::vector words{"Alex"sv, "Bob"sv, "Chad"sv, "Dave"sv};
    for(const auto &word :words){
        std::cout << word << ' ';
    }
    std::cout << '\n';


    //反向
    for(const auto & word : std::views::reverse(words)){
        std::cout << word << ' ';
    }
    std::cout << '\n';

    return 0;
}
