#include<iostream>
// #include<math.h> //c库
#include<cmath> //c++库


class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    // explicit Fraction()
    // {

    // }
    explicit Fraction(int numerator=0,int denominator=1)
        : m_numerator{numerator}
        , m_denominator{denominator}
        {

        }

    void getFraction()
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> m_numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> m_denominator;
        std::cout << '\n';
    }

    Fraction multiply(const Fraction &f)const
    {
        return Fraction{f.m_numerator * m_numerator, f.m_denominator * m_denominator};
    }
    void printFraction(const Fraction &f)const{
        std::cout << f.m_numerator << '/' << f.m_denominator << '\n';
    }

};


int main()
{
    Fraction f1{};
    Fraction f2{};
    f1.getFraction();
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    f1.printFraction(f1.multiply(f2));

    return 0;
}
