#include<bitset> //c++11
#include<format>//c++20
#include<iostream>

//进制
int main()
{
    //二进制
    int d{0b1010};
    //十进制
    int a{10};
    //八进制 文本前加 0
    int b{012};
    //十六进制 文本前加 0x
    int c{0xA};
    std::cout << d << '\n';
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';


    //数字分隔符 但是分隔符不能出现在第一个数字前
    long e{2'234'565'767};
    int f{0b1000'1010};
    std::cout << e << '\n';
    std::cout << f << '\n';

    //以十进制 八进制或十六进制输出值
    int x{12};
    std::cout << std::oct << x << '\n'; //std::oct 八进制
    std::cout << std::hex << x << '\n'; //std::hex 十六进制
    std::cout << std::dec << x << '\n'; //std::dec 十进制

    std::cout << "0b11 dec: " << std::dec <<0b11  << '\n';



    //输出二进制 std::bitset 需要 #include<bitset>
    //std::bitset<8> ->告诉编译器想储存8bit的二进制数
    std::bitset<8> bin1{0b100010100};
    std::bitset<8> bin2{0b11010};
    std::cout << "bin1: " << bin1 << '\n'; //输出00010100 只从低位到高位选取8位输出

    std::cout << "bin2: " << bin2 << '\n'; //输出00011010 不够补零

    //c++20 的新格式库
    std::cout << std::format("输出类似python的format,十进制: {:}\n", 0b10001000);
    std::cout << std::format("输出类似python的format,二进制: {:b}\n", 0b10001000);
    //std::cout << std::format("输出类似python的format,二进制: {:h}\n", 0b10001000);

    return 0;
}
