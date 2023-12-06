#include<iostream>


class Fraction
{
    private :
        int m_numerator{0};
        int m_denominator{1};
    public :
        Fraction(int numerator=0,int denominator=1)
            : m_numerator{numerator}
            , m_denominator{denominator}
            {}
        //同样可以显示的定义自己的复制构造函数
        Fraction(const Fraction &f)
            : m_numerator{f.m_numerator}
            , m_denominator{f.m_denominator}
            {
                std::cout << "复制构造函数!!\n";
            }

        void print()
        {
            std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
        }
};
/*
Q 注意到复制构造函数的参数必须是 （const） 引用。为什么不允许我们使用按值传递？
A 如果复制构造函数使用按值传递，则复制构造函数需要调用自身以将初始值设定项参数复制到复制构造函数参数中。
  但是，对复制构造函数的调用也将按值传递，因此将再次调用复制构造函数以将参数复制到函数参数中。
  这将导致对复制构造函数的无限调用链
*/

int main()
{
    Fraction f{5, 3};
    Fraction fcopy{f};//复制构造函数
    f.print();
    fcopy.print();
    return 0;
}
