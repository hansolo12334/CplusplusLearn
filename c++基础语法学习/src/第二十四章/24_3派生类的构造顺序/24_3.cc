
/*

    派生实际上是两个部分：一个是基础部分，另一个是派生部分。当 C++ 构造派生对象时，它会分阶段进行。首先，首先构造最基的类（在继承树的顶部）。然后按顺序构造每个子类，直到最后构造最多子类（在继承树的底部）。

*/
#include <iostream>

class Base
{
public:
    int m_id {};

    Base(int id=0)
        : m_id { id }
    {
        std::cout << "Base\n";
    }

    int getId() const { return m_id; }
};

class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0)
        : m_cost { cost }
    {
        std::cout << "Derived\n";
    }

    double getCost() const { return m_cost; }
};

int main()
{
    std::cout << "Instantiating Base\n";
    Base base;

    std::cout << "Instantiating Derived\n";
    Derived derived;
    //输出 : 基类先构造 子类后构造
    /*
        Instantiating Base
        Base
        Instantiating Derived
        Base
        Derived
    */
    return 0;
}
