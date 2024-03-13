#include<iostream>


class Base
{
public:
    int m_public {}; // 可以被任何人访问
protected:
    int m_protected {}; // 可以被基类访问, 朋友,和派生类
private:
    int m_private {}; // 只能被基类成员和朋友访问(不是派生类)
};

class Derived: public Base
{
public:
    Derived()
    {
        m_public = 1; // 允许访问：能从派生类访问公共基类成员
        m_protected = 2; // 允许访问: 能从派生类访问保护的基类成员
        m_private = 3; // 不允许访问: 能从派生类访问私有的基类成员
    }
};

//首先，类有三种不同的方式从其他类继承：public、protected 和 private。

// 公共的从基类继承
class Pub: public Base
{
};

// 受保护的从基类继承
class Pro: protected Base
{
};

// 私有的从基类继承
class Pri: private Base
{
};

class Def: Base // 默认时私有的继承
{
};
//在实践中，私有继承很少被使用。
int main()
{
    Base base;
    base.m_public = 1; // 允许访问: 能从类外访问公共成员
    base.m_protected = 2; // 不允许访问: 不能从类外访问受保护的成员
    base.m_private = 3; // 不允许访问: 不能从类外访问私有的成员

    return 0;
}
