

/*
 当使用派生类对象调用成员函数时，编译器首先查看该成员是否存在于派生类中。
  如果没有，它将开始向上遍历继承链，并检查是否已在任何父类中定义该成员。它使用它找到的第一个。

  换句话说，它使用它能找到的函数的最派生版本
*/


#include <iostream>

class Base
{
protected:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }

    friend std::ostream& operator<< (std::ostream& out, const Base& b)
	{
		out << "In Base\n";
		out << b.m_value << '\n';
		return out;
	}

};

class Derived: public Base
{
public:
    Derived(int value)
        : Base { value }
    {
    }

    int getValue() const { return m_value; }

    // Here's our modified function
    void identify() const {
        //使用范围解析运算符
        Base::identify();
        std::cout << "I am a Derived\n";
    }

    friend std::ostream& operator<< (std::ostream& out, const Derived& d)
	{
		out << "In Derived\n";
		// static_cast Derived to a Base object, so we call the right version of operator<<
		out << static_cast<const Base&>(d);
		return out;
	}
};



int main()
{
    Base base { 5 };
    base.identify();

    Derived derived { 7 };
    derived.identify();
    std::cout << '\n';

    std::cout << derived;
    return 0;
}
