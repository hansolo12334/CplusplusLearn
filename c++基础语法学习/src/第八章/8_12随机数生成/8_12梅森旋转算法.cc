#include<iostream>
#include<random>


//要访问C++中的任何随机化功能，我们包含了标准库的 <random> 标头

//使用梅森旋转算法在C++中生成随机数

/*
Mersenne Twister PRNG，除了有一个好名字，可能是所有编程语言中最受欢迎的PRNG。
虽然按照今天的标准，它有点旧，但它通常会产生高质量的结果并且具有不错的性能。随机库支持两种梅森费尔托斯特类型：
mt19937 是一个生成 32 位无符号整数的梅森旋转算法
mt19937_64 是一个生成 64 位无符号整数的梅森旋转算法
*/

void generate_random()
{
    std::mt19937 mt{}; //实例化一个32位的梅森旋转引擎

    for (size_t i = 0; i < 40; i++)
    {
        std::cout << mt() << '\t';//生成一个随机数
        if (i%5==0)
        {
            std::cout << '\n';
        }
    }
}

void generate_unifrom_random()//生成指定范围内的随机数
{
    std::mt19937 mt{};
    std::uniform_int_distribution die6{1, 6};
    // 对于 C++14, 使用std::uniform_int_distribution<> die6{ 1, 6 };
    std::cout << '\n';
    for (size_t i = 0; i < 40; i++)
    {
        std::cout << die6(mt) << '\t';//生成一个随机数
        if (i%10==0)
        {
            std::cout << '\n';
        }
    }
}

//初始化随机数种子
//使用系统时钟
//使用系统的随机设备


int main()
{

    //generate_random();
    generate_unifrom_random();
    return 0;
}
