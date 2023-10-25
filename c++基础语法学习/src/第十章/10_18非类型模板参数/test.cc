#include <iostream>

void print()
{
    std::cout << "void\n";
}

void print(int x=0)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5.0f);
    //print();
    //由于具有默认参数的参数不计入解析重载函数，
    //编译器无法确定是 print()还是print(int)

    return 0;
}
