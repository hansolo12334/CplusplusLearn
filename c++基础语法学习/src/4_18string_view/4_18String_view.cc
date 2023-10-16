#include<iostream>
#include<string_view>

// std::string_view c++17标准 正如其名 只查看当下这个字符串

void printString(std::string str1)//这里 str 复制了一份 不好
{

    std::cout << str1 << '\n';
}
//string_view不做字符串拷贝 不分配内存 提供对现有字符串的只读访问 而无需创建副本。只读意味着我们可以访问和使用正在查看的值，但我们不能修改它
void printSV(std::string_view str)
{
    std::string_view ss{str};
    std::cout << str << '\n';
}
//当需要只读字符串时，尤其是对于函数参数，首选std::string_view
int main()
{
    std::string_view s{"hansolo",3};

    //std::cout << &s<<'\n';
    std::string s1("hansolo",3);
    printSV(s);
    printString(s1);
    //std::cout << &s1<<'\n';

    //string_view初始化
    std::string_view s2{"han"};//c样式字符串 初始化

    std::string s3{"hans"};
    std::string_view s4{s3};//string 样式 初始化

    std::string_view s5{s4};//string_view 样式 初始化

    //string_view参数 会接受不同类型的字符串参数 来隐式的转换为std::string_view 比如
    printSV("hello"); //c风格的字符串
    printSV(s4); //string 风格字符串
    printSV(s5); //std::string_view风格字符串

    //但是std::string_view不会隐式转换为string 如下
    //printString(s5); //报错: 不存在用户定义的从 "std::string_view" 到 "std::string" 的适当转换C/C++(312)
    //如果需要转换
    //1.
    printString(std::string{s5});
    //2. 通过 static_cast 运算符进行显式类型转换
    printString(static_cast<std::string>(s5));
    return 0;
}
