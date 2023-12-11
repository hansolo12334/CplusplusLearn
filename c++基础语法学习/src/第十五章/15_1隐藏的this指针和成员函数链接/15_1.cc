#include<iostream>

//在每个成员函数中，关键字 this 是一个常量指针，
// 用于保存当前隐式对象的 地址 。


//啥时候用this 一般不太用 若有歧义 变量名称重复的情况 可用this
// 但是 使用 m_来区分私有变量不香么
class Employee
{
private:
    int m_salary{};

public:
    explicit Employee(int salary)
        : m_salary{salary}
        {

        }

    int getSalary()const
    {
        return this->m_salary;
    }
    void setSalary(int s)
    {
        this->m_salary = s;
        // std::cout << this;

    }
};

int main()
{
    Employee hansolo{20000};
    std::cout << hansolo.getSalary() << '\n';
    hansolo.setSalary(1000000000);
    std::cout << hansolo.getSalary() << '\n';
    return 0;
}
