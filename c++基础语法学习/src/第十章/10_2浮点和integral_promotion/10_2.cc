#include<iostream>





/*
    Numeric promotion 数字提升
    C++非正式地定义了一类类型转换，称为 numeric promotions.
    数值提升是某些较窄的数值类型（如 char ）到某些较宽的数值类型（通常为 int 或 double ）的类型转换，这些类型可以有效处理，并且不太可能产生溢出的结果

    所有数值提升都是值保留的，这意味着转换后的值将始终等于源值（它只是具有不同的类型）。
    由于源类型的所有值都可以在目标类型中精确表示，因此保留值的转换称为“安全转换”。

    由于升级是安全的，因此编译器将根据需要自由使用数字升级，并且在这样做时不会发出警告


    使用积分提升(integral promotion )规则，可以进行以下转换：
    1. 有符号字符或带符号短字符可以转换为 int。
    2. 如果 int 可以保存类型的整个范围，则可以将无符号字符、char8_t 和无符号 short 转换为 int，否则也可以转换为无符号 int。
    3. 如果 char 默认是有符号的，则遵循上述signed char 转换规则。如果默认情况下它是无符号的，则遵循上述无符号字符转换规则。

*/

void printInt(int x)
{
    std::cout << x << '\n';
}
int main()
{
    short s{3};
    printInt(s);

    printInt('a');  // 输出 a的 ASCII码 97
    printInt(true); // 输出 1

    return 0;
}
