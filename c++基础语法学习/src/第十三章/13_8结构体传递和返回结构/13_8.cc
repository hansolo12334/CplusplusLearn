#include<iostream>


struct Employee
{
    int id{};
    int age{};
    double wage{};
};


//通过引用方法传递结构:
void printEmployee(Employee &emp)
{
    std::cout << "ID: " << emp.id << '\n';
    std::cout << "Age: " << emp.age << '\n';
    std::cout << "Wage: " << emp.wage << '\n';
    std::cout << '\n';
}

//返回结构
Employee getEmployee()
{
    Employee ee{2, 33, 30000};
    return ee;
}//结构通常按值返回，以免返回悬空引用

Employee returenInBraces()
{
    return {3, 92, 0.0};
}

int main()
{
    Employee hansolo{1, 22, 20000};
    printEmployee(hansolo);


    Employee tom{getEmployee()};
    printEmployee(tom);

    Employee Nike{returenInBraces()};

     printEmployee(Nike);

    return 0;
}
