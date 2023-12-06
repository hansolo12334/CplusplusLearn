#include<iostream>
#include<string>
#include<string_view>



class Employee
{
    private :
        std::string m_name{};
        int m_id{0};

    public :

    // 构造函数可以将初始化委托（转移责任）给来自同一类类型的另一个构造函数。
    // 此过程有时称为构造函数链接，此类构造函数称为委托构造函数

    // 若要使一个构造函数将初始化委托给另一个构造函数，
    // 只需在成员初始值设定项列表中调用该构造函数即可
        Employee(std::string_view name)
            : Employee{name,0}
            {}


        Employee(std::string_view name,int id)
            : m_name{name}
            , m_id{id}
            {
                std::cout << "Emloyee " << m_name << " created\n";
            }
};


int main()
{
    Employee e1{"Hans"};
    Employee e2{"Solo", 23};
    return 0;
}
