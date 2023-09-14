#include<string>
#include<iostream>


int main()
{
    //在现代c++中，最好避免使用C样式的字符串变量

    std::string name{};
    name = "hansolo";
    std::cout << name << '\n';


    //string可以容纳不同大小的字符串
    std::cout << "输入字符串: " << '\n';
    std::string inputString{};
    std::cin >> inputString; //han solo
    std::cout << "输入的字符串是: "<< inputString << '\n';
    //但是 只输出han 为什么？ 因为 cin遇到第一个空格返回 其他字符仍然留在cin中,

    return 0;
}
