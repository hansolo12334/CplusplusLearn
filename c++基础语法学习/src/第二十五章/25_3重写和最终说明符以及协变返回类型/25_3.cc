#include <iostream>
#include <string_view>


//只有当派生类的签名和返回类型完全匹配时，才将其视为重写

class A
{
public:
	virtual std::string_view getName1(int x) { return "A"; }
	virtual std::string_view getName2(int x) { return "A"; }
    virtual std::string_view getName3(int x) { return "A"; }
};



class B : public A
{
public://虚函数的参数 和基类函数声明的 参数类型不同  因此不被视为 基类A的重写
	// virtual std::string_view getName1(short x) override { return "B"; } // note: parameter is a short
	// virtual std::string_view getName2(int x)  const override { return "B"; } // note: function is const


    virtual std::string_view getName3(int x) override{
        return "B";
    }
};

/*
为了帮助解决本应重写但不是重写的函数的问题，
可以通过将 override 说明符放在函数签名之后（函数级常量说明符所在的位置相同）来将重写说明符应用于任何虚函数。
上面class B的前两个虚函数加上 override 后，会报错 ：使用“override”声明的成员函数不能重写基类成员
*/
//使用替代说明符不会降低性能 有助于确保您实际上已覆盖了您认为拥有的函数
//应使用替代说明符标记所有虚拟替代函数
//因此无需使用带有 virtual 关键字的覆盖说明符来标记函数

#define ADD(x,y) ((x)+(y))


int main()
{
    B b{};
    A& rBase{ b };
    std::cout << rBase.getName1(1) << '\n';
    std::cout << rBase.getName2(2) << '\n';
    //输出为 A A


    return 0;
}
