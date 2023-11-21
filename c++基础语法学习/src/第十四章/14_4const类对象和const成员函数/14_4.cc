#include<iostream>


//所以const变量必须在创建时初始化

struct Date
{
    int year{};
    int month{};
    int day{};

    void increamentDay(){
        ++day;
    }
    //为了解决无法调用的问题 可以创建一个const成员函数 前提是该函数内没有的成员变量进行修改 只是调用了而已
    void showDate() const
    {
       // year = year + 1; 不能直接修改 会报错
        int newyear = year + 1;
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main()
{
    const Date today{2023, 11, 21};

    //不允许修改 const 对象的数据成员
    //today.increamentDay();//报错 不能call const object
    today.showDate();
    return 0;
}
