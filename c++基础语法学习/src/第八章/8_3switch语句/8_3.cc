#include<iostream>


void printDigitName(int x)
{
    using std::cout;
    switch (x)
    {
    case 1:
        cout << "One\n";
        break;
    case 2:
        cout << "Two\n";
        break;
    case 3:
        cout << "Three\n";
        break;
    default://默认 写在最后
        cout << "Unknow\n";
        break;
    }
}

void printDigitName1(int x)
{
    using std::cout;

    switch (x)
    {
    case 1:
        cout << "One\n"; //会警告 ： 8_3.cc:31:17: warning: this statement may fall through [-Wimplicit-fallthrough=]
        //break;
        [[fallthrough]];
    case 2:
        cout << "Two\n";
        int y;
        y = x; //可以在case内声明变量
        //int z{0};//但不能初始化
        //虽然变量 y 在 case2 中定义，但它也被用在 中 case 1 case 2 3。交换机内的所有语句都被视为同一作用域的一部分。因此，在一种情况下声明或定义的变量可以在以后的情况下使用，即使定义变量的情况从未执行（因为开关跳过了它）！
        // [[fallthrough]];
        //break;
    case 3:
        cout << "Three\n";
        cout << y << '\n';//这里没问题！
        [[fallthrough]];
        //break;
    default://默认 写在最后
        cout << "Unknow\n";
        //break;
    }
}//输入2  输出 Two Three Unknow 不正确！


/*
[[fallthrough]] 属性

注释有意的故障是告诉其他开发人员预期故障的常见约定。
虽然这适用于其他开发人员，但编译器和代码分析工具不知道如何解释注释，因此它不会摆脱警告。

为了帮助解决此问题，C++17 添加了一个名为 [[fallthrough]] 的新属性。

属性(Attributes)是一项现代C++功能，它允许程序员向编译器提供有关代码的一些附加数据。
若要指定属性，属性名称放在双括号之间。
属性不是语句 - 相反，它们几乎可以在与上下文相关的任何地方使用。

说白了就是为了就是要这样写程序来完成特定功能，但不想让编译器警告，就加上[[fallthrough]]
*/


int main()
{
    int digit{1};
    std::cout << "input a number:";
    std::cin >> digit;
    printDigitName1(digit);
    return 0;
}
