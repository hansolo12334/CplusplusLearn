#include<iostream>


struct Fraction
{
    double getResult()//成员函数
    {
        return this->x*1.0 / this->y;
    }

    public://访问限定符
        int x{};
        int y{};
        double c {getResult()};
};

struct Fraction_inher : Fraction //struct也能继承！！？？
{
    double add()
    {
        return x + y;
    }
    double c{add()};
};


int main()
{

    Fraction f{5, 2};
    std::cout << f.c << '\n';

    Fraction_inher f1{3, 4};
    std::cout << f1.c << '\n';

    return 0;
}
