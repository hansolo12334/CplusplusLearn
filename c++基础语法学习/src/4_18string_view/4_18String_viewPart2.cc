#include<iostream>
#include <string>
#include <string_view>



std::string getName()
{
    std::string s { "Alex" };
    return s;
}

int main()
{
    std::string_view sv{};
    {
        std::string s{"hello"};
        sv = s;// sv is now viewing s
    }
    std::cout << sv << '\n';

    std::string_view name { getName() }; // name initialized with return value of function
    std::cout << name << '\n'; // undefined behavior ????没出错

    return 0;
}
