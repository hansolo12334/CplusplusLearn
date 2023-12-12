#include<iostream>

//有时候 想在类对象销毁时 做一下事情 比如清理内存等等 怎么办
// 如何自动清理？


// 之前学习到的构造函数， 是在创建非聚合类类型的对象调用的特殊成员函数，它用来初始化成员变量，并且执行一些其他任务

//与构造函数类似的， 当非聚合类类型销毁时，该函数会自动调用，
// 它叫析构函数 允许在销毁类的对象之前进行任何有必要的清理


/*
析构函数命名
    1.析构函数必须与类同名，前面有一个波浪号 （~）。
    2.析构函数不能接受参数。
    3.析构函数没有返回类型。
 一个类只能有一个析构函数。
  通常，不应显式调用析构函数（因为当对象被销毁时，它会自动调用），因为在极少数情况下，会希望多次清理对象

析构函数可以安全地调用其他成员函数，因为在析构函数执行之前不会销毁对象
*/

class Date
{
private:
    int m_year{2023};

public:
    Date(int year=2023)
        : m_year{year}
        {
            std::cout << "构造Date "<<m_year<<'\n';
        }
    ~Date()
    {
        std::cout << "析构Date!\n";
    }

    int getYear()const{
        return m_year;
    }
};


int main()
{
    {
        Date yesterday{2022};
    }//离开代码块 yesterday销毁
    Date today{};
    std::cout << today.getYear() << '\n';
    return 0;
}
