#include<iostream>
#include<string>
#include<string_view>


// 人 类
class Person
{
public:
    std::string m_name{};
    int m_age{};

    Person(std::string_view name="", int age=0)
     : m_name{name}
     , m_age{age}
     {}

     const std::string &getName() const{
         return m_name;
     }
     int getAge() const{
         return m_age;
     }
};

// BaseBall Player类 我们还想跟踪棒球运动员的姓名和年龄，
// 并且我们已经将这些信息作为 Person 类的一部分

// 使 BaseballPlayer 成为派生类

class BaseballPlayer : public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage=0.0,int homeRuns=0)
     : m_battingAverage{battingAverage}
     , m_homeRuns{homeRuns}
     {}

};

class Employee: public Person //员工
{
public:
    double m_hourSalary{};
    long m_employeeId{};

    Employee(double hourSalary = 0.0,long employeeId=0)
     : m_hourSalary{hourSalary}
     , m_employeeId{employeeId}
     {}

    void printNameAndSalary() const{
        std::cout << m_name << ' ' << m_hourSalary << '\n';
    }
};

// 继承链  派生类也可以作为其他派生类的基类

class Supervisor: public Employee //主管
{
public:
    long m_overseesIds[5]{};
};


int main()
{
    BaseballPlayer hansolo{};

    hansolo.m_name = "hansolo";
    hansolo.m_battingAverage = 1.1;

    std::cout << hansolo.getName() << '\n';


    Employee jack{22.2,11223};
    jack.m_name = "jack";
    jack.printNameAndSalary();


    return 0;
}
