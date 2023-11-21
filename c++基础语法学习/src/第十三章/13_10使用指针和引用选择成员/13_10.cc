#include<iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

//对象的引用
void printEmployee(const Employee &emp)
{
    std::cout << emp.age << '\n';
    std::cout << emp.id << '\n';
    std::cout << emp.wage << '\n';
}




int main()
{
    Employee hansolo{0, 22, 10000};
    printEmployee(hansolo);

    //指向结构的指针的成员选择 使用->
    Employee *Joe{&hansolo};
    std::cout << (*Joe).age << '\n';
    std::cout << Joe->age << '\n';
    //(*Jeo).age == Jeo->age
    //使用指针访问成员的值时，使用指针运算符 （->） 而不是成员选择运算符 （.） 的成员选择。

    //Employee * Tom{1, 23, 3000};
    Employee *tom = new Employee();
    *tom = {1, 25, 4000};
    std::cout << tom->age << '\n';

    return 0;
}
