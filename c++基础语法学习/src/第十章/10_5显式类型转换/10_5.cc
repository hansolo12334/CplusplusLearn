#include<iostream>



// C++支持 5 种不同类型的转换：
// C-style casts 、、 dynamic casts 、 static casts、const casts 和 reinterpret casts 。后四个有时被称为named casts
// Const casts 和 reinterpret casts 通常应避免使用，因为它们仅在极少数情况下有用，如果使用不当可能会有害
// 避免使用常量强制转换并重新解释强制转换

// 在标准 C 编程中，强制转换是通过 （） 运算符完成的，使用类型名称来转换放在括号内的值。
// 您可能仍然会看到这些在从 C 转换的代码（或由程序员）中使用。
int main()
{
    int x{10};
    int y{4};

    // C语言风格的转换
    double d{(double)x / y};
    std::cout << "c style " << d << '\n'; // 2.5

    //避免使用 C 样式转换

    //C++风格的转换
    //static_cast
    // static_cast 运算符将表达式作为输入，并返回转换为尖括号内指定的类型的计算值。
    // static_cast 最适合用于将一种基本类型转换为另一种基本类型。

    double d1{static_cast<double>(x) / y};
    std::cout << "c++ style " << d1 << '\n';

    //使用static_cast明确缩小转化范围
    //例子1
    int i{67};
    //char ch = i; //别使用不安全
    char ch{static_cast<char>(i)};

    std::cout << "c++ style " << ch << '\n';

    //例子2

   // i = i / 2.5; //别使用不安全
    i = static_cast<int>(i / 2.5);

    return 0;
}
