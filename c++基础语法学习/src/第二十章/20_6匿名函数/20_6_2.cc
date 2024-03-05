#include<iostream>
#include<array>
#include<string_view>
#include<algorithm>
#include<functional>


//传递 lambda函数到 函数


// 1 使用 std::function
void repeat1(int times, const std::function<void(int)> &func)
{
    for (int i = 0; i < times;i++)
    {
        func(i);
    }
}

// 2 使用函数模板类型

template<typename T>
void repeat2(int times, const T &func)
{
    for (int i = 0; i < times;i++)
    {
        func(i);
    }
}

//c++20 使用简短的函数模板语法
void repeat3(int times,const auto &func)
{
    for (int i = 0; i < times;i++)
    {
        func(i);
    }
}



int main()
{
    auto myfunc{[](int i) {
        std::cout << i <<' ';
        }
    };

    repeat1(3,myfunc);
    repeat2(3, myfunc);
    repeat3(3, myfunc);

    return 0;
}
