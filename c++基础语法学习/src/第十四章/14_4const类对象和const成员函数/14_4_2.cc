#include<iostream>

struct Date
{
    int year{};
    int month{};
    int day{};

    void print(){
        std::cout << "none-const! ";
        std::cout << year << '/' << month << '/' << day << '\n';
    }

    //成员函数也可以进行const 和 none-const重载
    void print() const{//静态成员
        std::cout << "const! ";
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main()
{
    //根据对象const与否判断
    Date today{2023, 11, 22};
    today.print(); //print还有1个重载 这里使用了非静态的重载 print

    const Date yesterday{2023, 11, 21};
    yesterday.print(); //这里使用了静态的重载 print

    return 0;
}
