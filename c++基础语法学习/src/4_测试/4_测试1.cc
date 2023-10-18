#include<iostream>



//Q1 为什么符号常量通常比文字常量更好？为什么 const/constexpr 符号常量通常比 #defined 符号常量更好？
//A1  在程序中使用文字常量（又名幻数）会使程序更难理解和修改。符号常量有助于记录数字实际表示的内容，
//在声明时更改符号常量会更改其使用位置的值。#define 常量不会显示在调试器中，并且更有可能发生命名冲突。


//Q2 在以下每种情况下为变量选择适当的数据类型。尽可能具体。如果答案是整数，
//请根据范围选择 int（如果大小不重要）或特定的固定宽度整数类型
//（例如 std：：int16_t）。如果变量应该是常量，请说出来。

//Q2.1 用户的年龄（以年为单位）（假设类型的大小并不重要）
//A2.1  int

//Q2.2 用户是否希望应用程序检查更新
//A2.2 bool

//Q2.3 pi (3.14159265)
//A2.3 constexpr double

//Q2.4 教科书的页数（假设大小并不重要）
//A2.4 int 由于书籍可能不会超过 32,767 页，因此 int 在这里应该没问题。

//Q2.5 沙发的长度（以英尺为单位），精确到小数点后 2 位（假设大小很重要）
//A2.5 float

//Q2.6 你从出生开始眨了多少次眼（注意：答案是百万）
//A2.6 std::int32_t

//Q2.7 用户通过字母从菜单中选择选项
//A2.8 char

//Q2.9 某人出生的年份（假设大小很重要）
//Q2.9 std::int16_t 可以使用正数表示 AD 出生日期，使用负数表示 BC 出生日期


//Q3 编写以下程序：要求用户输入 2 个浮点数（使用双精度）。然后要求用户输入以下数学符号之一：+、-、* 或 /。程序根据用户输入的两个数字计算答案并打印结果。如果用户输入无效的符号，程序应不打印任何内容。
double get_doubleValue()
{
    std::cout << "Enter a double value:";
    double value{};
    std::cin >> value;
    return value;
}
char getOperator()
{
    std::cout << "Enter one of the following: +,-,*,or /:";
    char symbols1{};
    std::cin >> symbols1;
    return symbols1;
}
void printResult(double value1,double value2,char symbols1){
    if(symbols1=='+'){
        std::cout << value1 << " " << symbols1 << " " << value2 << " is " << value1 + value2 << "\n";
    }
    if(symbols1=='-'){
        std::cout << value1 << " " << symbols1 << " " << value2 << " is " << value1 - value2 << "\n";
    }
    if(symbols1=='*'){
        std::cout << value1 << " " << symbols1 << " " << value2 << " is " << value1 * value2 << "\n";
    }
    if(symbols1=='/'){
            std::cout << value1 << " " << symbols1 << " " << value2 << " is " << value1 / value2 << "\n";
    }
}
int main()
{
    double value1{get_doubleValue()};
    double value2{get_doubleValue()};
    char symbols1{getOperator()};
    printResult(value1, value2, symbols1);

    return 0;
}
