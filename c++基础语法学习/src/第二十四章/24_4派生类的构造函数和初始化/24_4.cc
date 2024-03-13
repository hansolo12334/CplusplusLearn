#include<iostream>

// 在创建派生类对象时 如何初始化基类的对象？



// 构造函数只能从其直接父类/基类调用构造函数。
 // 因此，C 构造函数无法直接调用参数或将参数传递给 A 构造函数。
 // C 构造函数只能调用 B 构造函数（它负责调用 A 构造函数）


// 当派生类被销毁时，每个析构函数都按相反的构造顺序调用。
// 在上面的例子中，当 c 被销毁时，首先调用 C 析构函数，
// 然后调用 B 析构函数，然后调用 A 析构函数。

class Base
{

private:
    int m_id{};
public:


    Base(int id=0)
    : m_id{id}
    {

    }
    int getId() const{
        return m_id;
    }
};

class Derived : public Base
{

private:
    double m_cost{};

public:
    Derived(int id=0,double cost=0.0)
     : Base{id} //这样初始化 基类
     , m_cost{cost}
     {

     }

     double getCost()const{
         return m_cost;
     }
};


int main()
{
    Derived derived{2, 1.2};
    std::cout << "Id " << derived.getId() << '\n';
    std::cout << "Cost " << derived.getCost() << '\n';
    return 0;
}
