#include<iostream>
#include<string.h>

//我们可以定义一个程序定义类型（在全局范围内），然后将其用作另一个程序定义类型的成员
struct Empolyee
{
    int id{};
    int age{};
    double wage{};
};

struct Company
{
    int numberOfEmployees{};
    Empolyee CEO{};

};

//其次，类型也可以嵌套在其他类型中:
struct Food
{
    struct Fruits
    {
        std::string name{};
        double price{};
    };

    int typesNum{};
    Fruits apple{};
};



int main()
{
    Company myCompany{7, {1, 32, 55000.0}};
    std::cout << myCompany.CEO.wage << '\n';

    Food myFoods{1,{"apple",2.0}};
    std::cout << myFoods.apple.name << '\n';


    std::cout << "The size of int is " << sizeof(int) << " bytes\n";
    std::cout << "The size of std::string is " << sizeof(std::string) << " bytes\n";
    std::cout << "The size of double is " << sizeof(double) << " bytes\n";
    std::cout << "The size of Food is " << sizeof(Food) << " bytes\n";
    /*
    The size of int is 4 bytes
    The size of std::string is 32 bytes
    The size of double is 8 bytes
    The size of Food is 48 bytes
    可以看出 结构体的大小不等于三个类型大小之和 因为出于性能原因，编译器有时会在结构中添加间隙（这称为填充）
    */
    return 0;
}
