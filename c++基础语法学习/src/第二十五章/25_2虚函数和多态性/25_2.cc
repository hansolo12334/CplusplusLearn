#include <iostream>
#include<string_view>


/*
虚函数是一种特殊类型的成员函数，在调用该函数时，该函数将解析为所引用或指向的对象的实际类型的函数的最派生版本。

如果派生函数与函数的基本版本具有相同的签名（名称、参数类型以及是否为 const）和返回类型，则该派生函数被视为匹配函数。此类函数称为替代(override)

要使函数虚拟化，只需将“virtual”关键字放在函数声明之前即可。
*/

class Base
{
public:
    virtual std::string_view getName() const{
        return "Base";
    }
    virtual ~Base() = default;
};

class Derived: public Base
{
public:
    virtual std::string_view getName() const{
        return "Derived";
    }
};
//如果函数是虚拟的，则派生类中的所有匹配重写都是隐式虚拟的。
//反之则不行——派生类中的虚拟重写不会隐式地使基类函数成为虚拟函数

int main()
{
    Derived derived{};
    Base &rbase{derived};
    std::cout <<"rbase is a "<< rbase.getName() << '\n';

    //请注意！！！ 仅当通过 指针 或 对类类型对象的引用 调用虚拟成员函数时，虚拟函数解析才有效。之所以有效，是因为编译器可以将指针或引用的类型与指向或引用的对象的类型区分开来

    //仅当通过指针或对类类型对象的引用调用成员函数时，虚函数解析才有效
    Derived derived1{};
    Base base1{derived1};//不是引用或指针
    std::cout <<"base1 is a "<< base1.getName() << '\n';
    return 0;
}

/*
不要从构造函数或析构函数调用虚函数
 创建派生类时，首先构造 Base 部分。
 如果要从 Base 构造函数调用一个虚拟函数，
 并且该类的 Derived 部分甚至尚未创建，
 则它将无法调用该函数的 Derived 版本，
 因为没有 Derived 对象可供 Derived 函数处理。
 在 C++ 中，它将改为调用基本版本。

 析构函数也存在类似的问题。
 如果在基类析构函数中调用虚函数，它将始终解析为该函数的基类版本，因为该类的 Derived 部分已被销毁
*/
