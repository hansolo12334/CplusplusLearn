#include<iostream>


//所以const变量必须在创建时初始化

struct Date
{
    int year{};
    int month{};
    int day{};

    void increamentDay(){ //非const成员
        ++day;
    }
    //为了解决无法调用的问题 可以创建一个const成员函数 前提是
    //该函数内没有的成员变量进行修改 只是调用了而已
    void showDate() const
    {
       // year = year + 1; 不能直接修改 会报错
        int newyear = year + 1;
        std::cout << year << '/' << month << '/' << day << '\n';
    }
    void modifiDate(){
        year = year + 1;
    }
};

int main()
{
    const Date today{2023, 11, 21};

    //不允许修改 const 对象的数据成员
    //today.increamentDay();//报错 不能call const object
    today.showDate();


    //可以在非常量对象上调用Const成员函数
    Date yesterday{2023, 11, 21};
    yesterday.modifiDate();
    yesterday.showDate();
    //由于可以在 const 和非 const 对象上调用 const 成员函数，因此，如果成员函数不修改对象的状态，则应将其设为 const
    //一个不（也永远不会）修改对象状态的成员函数应该被设为 const，以便可以在 const 和非 const 对象上调用它


    return 0;
}
