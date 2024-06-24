#include<iostream>
#include<string>
#include<string_view>
#include<memory>
// 最终说明符
/*
在某些情况下，可能不希望某人能够重写虚拟函数或从类继承。
最终说明符可用于告诉编译器强制执行此操作。
如果用户尝试重写函数或从已指定为 final 的类继承，编译器将给出编译错误。
*/

class A
{
public:
	virtual std::string_view getName() const { return "A"; }
};

class B : public A
{
public:
    //如果我们想限制用户覆盖函数，则最终说明符与覆盖说明符所在的位置相同，如下所示：
	std::string_view getName() const override final { return "B"; } // okay, overrides A::getName()
};

//如果我们想阻止从类继承，则在类名之后应用最终说明符：
class C final: public B
{
public:
	// std::string_view getName() const override { return "C"; }
    //  无法重写“final”函数 "B::getName" (已声明 所在行数:22)
};
//类 C 被声明为最终类。因此，当 D 尝试从 C 继承时，编译器将给出编译错误。

// class D: public C //不能将“final”类类型用作基类C/C++(1904)
// {
// };

//在一种特殊情况下，派生类虚函数重写可以具有与基类不同的返回类型，
// 但仍被视为匹配重写。如果虚函数的返回类型是对某个类的指针或引用，
// 则重写函数可以返回指针或对派生类的引用。这些称为协变返回类型。

class Base
{
public:
    virtual Base* getThis() {
        std::cout << "Base getThis()\n";
        return this;
    }

    void printType(){
        std::cout << "return Base\n";
    }
};

class Derived: public Base
{
public:
    Derived *getThis() override {
        std::cout << "Derived getThis()\n";
        return this;
    }
    void printType(){
        std::cout << "return Derived\n";
    }
};



int main()
{
    Derived d{};
    Base *b{&d};


    d.getThis()->printType();
    b->getThis()->printType();



    return 0;
}
// Q  我们什么时候使用函数重载与函数覆盖?
// A  当我们需要成员或非成员函数在传递不同类型的参数时行为不同时，使用函数重载
//    当隐式对象是派生类时，我们需要成员函数的行为方式不同时，使用函数覆盖
