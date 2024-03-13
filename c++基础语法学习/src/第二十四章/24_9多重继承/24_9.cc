//每个继承的类都有一个且只有一个父类。但是，C++ 提供了执行多重继承的功能。
// 多重继承使派生类能够从多个父类继承成员。

#include<iostream>
#include <string_view>

/*
假设我们想编写一个程序来跟踪一群老师。老师是一个人。
但是，教师也是雇员（如果为自己工作，他们是自己的雇主）。
多重继承可用于创建从 Person 和 Employee 继承属性的 Teacher 类。
若要使用多重继承，只需指定每个基类（就像在单次继承中一样），并用逗号分隔。
*/

//   应该不惜一切代价避免C++中的多重继承!!!

class Person
{
private:
    std::string m_name{};
    int m_age{};

public:
    Person(std::string_view name, int age)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

class Employee
{
private:
    std::string m_employer{};
    double m_wage{};

public:
    Employee(std::string_view employer, double wage)
        : m_employer{ employer }, m_wage{ wage }
    {
    }

    const std::string& getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }
};

// Teacher 多重继承了 Person 和 Employee
class Teacher : public Person, public Employee
{
private:
    int m_teachesGrade{};

public:
    Teacher(std::string_view name, int age, std::string_view employer, double wage, int teachesGrade)
        : Person{ name, age }, Employee{ employer, wage }, m_teachesGrade{ teachesGrade }
    {
    }
};


int main()
{
    Teacher t1{"hansolo", 24, "bo", 20000, 8};

    return 0;
}
