#include<iostream>
#include<string>

//C++ 具有三种不同的访问级别：公共、私有和受保护。

//默认情况下 struct的成员是公共的

//默认情况下 clsss的成员是私有的
class Date_errorExample
{
    //命名规则 使用m_前缀命名私有成员变量
    int m_year{};
    int m_month{};
    int m_day{};

    void print() const{
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }
};

class Date
{
    public:
        int year{};
        int month{};
        int day{};

        void print() const{
            std::cout << year << '/' << month << '/' << day << '\n';
        }
};


class Character
{
    public:
        Character(){}
        Character(std::string_view name, int age) : name(name), age(age){}
        Character(int age,std::string_view name){
            Character::age = age;
            Character::name = name;
        }

        std::string_view name{"hansolo"};
        int age{23};


        void getCharacterInfo()const{
            std::cout << name << " is " << age << " from " << m_nationality << '\n';
            // 虽然 m_nationality 是private变量 但是
            // getCharacterInfo() 是class的成员 类是允许成员访问私有成员的
        }

    private:
        std::string_view m_nationality{"China"};
};

// 最佳实践 struct 应完全避免访问说明符 (所有成员都将默认为 public) 使其保持聚合
// 通过访问说明符设置访问级别
// 默认情况下，struct(unions) 的成员是公共的，类的成员是私有的
// class 成员 默认是私有的 虽然不写private也行 但是最好还是写上访问说明符以区别struct和class

// 最佳实践 class通常应将成员变量设为私有（或受保护），并将成员函数设为公共
// struct 通常应避免使用访问说明符（所有成员都将默认为 public）
int main()
{
    // Date_errorExample today{2023,11,22};//会报错

    Date today{2023, 11, 22};
    today.print();


    Character person1{};
    person1.getCharacterInfo();


    Character person2{"bo",22};
    person2.getCharacterInfo();

    Character person3{22,"solo"};
    person3.getCharacterInfo();


    return 0;
}
