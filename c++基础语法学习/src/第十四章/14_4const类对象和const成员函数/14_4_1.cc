#include<iostream>

struct Date
{
    int year{};
    int month{};
    int day{};

    void print_none_const(){//非静态成员
         std::cout << year << '/' << month << '/' << day << '\n';
    }
    void print_const() const{//静态成员
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

//  date通过const引用传递 被视为const对象
//  但是data的 print_none_const不是静态成员
//  不能在const对象上调用none-const成员
// void printDate_none_const(const Date &date)
// {
//     date.print_none_const();
// }

// (Date &date) 和 (Date date) 的区别在于通过引用传递参数 不需要复制一次变量 且不能修改对象内容 保护了对象
void printDate_const(const Date &date)
{
    date.print_const();
}

int main()
{
    Date today{2023, 11, 22};
    today.print_none_const();

    //printDate_none_const(today);//报错

    printDate_const(today);


    return 0;
}
