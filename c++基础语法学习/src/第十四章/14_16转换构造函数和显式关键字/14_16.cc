#include<iostream>
#include<string>
#include<string_view>


class Foo
{
private:
    int m_x{};

public:
    Foo(int x)
        : m_x{x}
        {

        }

    int getX()const
    {
        return m_x;
    }
};

void printFoo(Foo f)
{
    std::cout << f.getX() << '\n';
}


class Employee
{
private:
    std::string m_name{};

public:
    Employee(std::string_view name)
        : m_name{name}
        {

        }
    std::string getName()const
    {
        return m_name;
    }
};


void printEmployeeName(Employee e)
{
    std::cout << e.getName() << '\n';
}


class Dollar
{
private :
    int m_dollars{};
public:
    explicit Dollar()
        {

        }
    explicit Dollar(int dollers)
        : m_dollars{dollers}
        {

        }

    int getDollars()const{
        return m_dollars;
    }
};
void printDollars(Dollar d)
{
    std::cout << d.getDollars() << '\n';
}
// /按值和显式构造函数返回
Dollar getDollar()
{
    return Dollar{}; //不报错
    // return {}; //
    // return 4; //不存在从 "int" 转换到 "Dollar" 的适当构造函数
}


int main()
{
    // 用户定义的转换
    printFoo(2);
    //构造函数初始化时 2被隐式的推导为int x 传入m_x{x}


    // 只能应用一个用户定义的转换

    //应用如下
    //报错:could not convert ‘(const char*)"hansolo"’ from ‘const char*’ to ‘Employee
    //因为构造函数的参数类型是string_view 而下面输入的是c类型的字符串类型 char 不能再从char 转换到string_view

    //printEmployeeName("hansolo");

    //如果想使用如下 需要这样
    using namespace std::literals;
    printEmployeeName("hansolo"sv);
    //或者这样
    printEmployeeName((std::string_view)"hansolo");

    //而显式的构造一个类 就不需要二次转换
    printEmployeeName(Employee{"hansolo"});


    //显式关键字 explicit (避免更大的项目出错)

    // 不想隐式的转换   可以使用 explicit 关键字告诉编译器不应将构造函数用作转换构造函数
    //然后这样隐式的转换就会报错：不存在从 "int" 转换到 "Dollar" 的适当构造函数
    // printDollars(2);
    printDollars(Dollar{2});
    //显式构造函数可用于直接初始化和列表初始化
    Dollar d1{1};

    return 0;
}


// 默认情况 使用explicit 来创建接受单个参数的构造函数
// 如果类型的转换是高性能的,也可以使用隐式转换
