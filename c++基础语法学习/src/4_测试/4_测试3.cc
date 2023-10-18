#include <cstdint> // for std::uint8_t
#include <iostream>

//Q 代码里有哪些问题？


int main()
{
    std::cout << "How old are you?\n";

    //std::uint8_t age{};//没必要使用 使用int就行 年龄不需要特定的最小整数宽度，因此可以删除 #include<cstdint>
    int age{};

    constexpr int lowest_age{16};
    std::cin >> age;

    std::cout << "Allowed to drive a car in Texas [";

    //if (age >= 16)// 16 可以看成magic number 因此可以用constexpr定义
    if (age >= lowest_age)
    {
        //std::cout << "x"; //x是字符，最好使用'' 而不是 ""，减少空间的浪费
        std::cout << 'x';
    }
    else
    {
    // std::cout << " ";//  是字符，最好使用'' 而不是 ""，减少空间的浪费
    std::cout << ' ';
    }

    std::cout << "]\n";

    return 0;
}
