#include<iostream>


//C++支持另一类数值类型转换，称为数值转换。这些数值转换涵盖了基本类型之间的其他类型转换。

int main()
{
    //有五种基本类型的数值转换。
    //1. 将integral type转换为任何其他integral type（不包括 integral promotions）：
    short s = 3;
    long l = 3;
    char ch = s;
    unsigned int u = 3;

    //2. 将浮点类型转换为任何其他浮点类型（不包括integral promotions）：
    float f = 3.8;        // 将 double 转换为 float
    long double ld = 3.0; // 将 double 转换为 long double

    //3. 将浮点类型转换为任意整型：
    int i = 3.5;          // 将 double 转换为 int

    //4. 将整型类型转换为任何浮点类型:
    double d = 3;

    //5. 将整型或浮点型转换为布尔值：
    bool b1 = 3;
    bool b2 = 3.0;

    std::cout << b1 << '\n';
    //大括号初始化严格禁止某些类型的数值转换 int x{3.5}; 会报错
    return 0;
}
