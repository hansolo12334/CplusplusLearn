#include<iostream>


class Base{

private:
    int m_value{};

public:
    Base(int value)
     : m_value{value}
     {

     }
     int getValue() const{
         return m_value;
     }
};

class Derived: public Base{

public :
    Derived(int value)
     : Base{value}
     {

     }
     //删除派生类中的函数
     int getValue() const = delete; // 调用会报错： 无法引用 函数 "Derived::getValue() const" (已声明 所在行数:29) -- 它是已删除的函数

 private:
     using Base::getValue; // 函数 "Base::getValue" (已声明 所在行数:15) 不可访问
};


int main()
{
    Derived dd{1};
    // std::cout<<dd.getValue(); //
}
