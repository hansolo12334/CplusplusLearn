/*
    对于依赖项与关联的区别，通常会存在一些混淆

    在 C++ 中，关联是一种关系，其中一个类作为成员保持与关联类的直接或间接“链接”。
     例如，Doctor 类具有指向其成员 Patients 的指针数组。您可以随时询问医生的病人是谁。
     Driver 类将驱动程序对象拥有的 Car 的 ID 保存为整数成员。驾驶员总是知道与它相关的汽车

    依赖项通常不是成员。相反，所依赖的对象通常根据需要实例化（例如打开文件以将数据写入其中），或作为参数传递到函数中（例如下面重载运算符中的 std：：ostream<<）

*/

#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0): m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point); // Point has a dependency on std::ostream here
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}

int main()
{
    Point point1 { 2.0, 3.0, 4.0 };

    std::cout << point1; // the program has a dependency on std::cout here

    return 0;
}
