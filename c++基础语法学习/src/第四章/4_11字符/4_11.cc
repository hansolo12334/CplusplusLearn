#include<iostream>

//char数据类型被设计为保存单个character. 字符可以是单个字母、数字、符号或空格
int main()
{
    char ch1 {0};//使用ASCII字符
    char ch3{'0'};//切勿混淆
    char ch2{'A'}; //使用字符文字直接初始化
    std::cout << ch1 << ch3 << ch2 << "\n";

    char inputCh{};
    std::cin >> inputCh; //输入90
    std::cout << inputCh << "\n";
    std::cin >> inputCh;
    // 请注意，std::cin 将允许您输入多个字符。但是，变量ch只能保存 1 个字符。因此，只有第一个输入字符被提取到变量ch中。其余的用户输入保留在 std::cin 使用的输入缓冲区中，并且可以通过后续调用 std::cin 来提取。
    std::cout << inputCh << "\n";
    //输出9 \n  0

    //'' 和 ""?    ''用于单字符 ""一般用于字符串 合理使用助于编译器优化 '\n'->转义序列 "/n"多字符文字
    //避免使用 wchar_t



    return 0;
}
