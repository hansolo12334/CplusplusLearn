#include<iostream>
#include<string.h>

struct FractionItem
{
    int numerator{};
    int denominator{};

};

FractionItem getFraction()
{
    FractionItem fi{};
    std::cout << "Enter a value for the numerator: ";
    std::cin >> fi.numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> fi.denominator;
    return fi;
}

constexpr std::string returnFraction(FractionItem fi1,FractionItem fi2)
{
    std::string result{};
    int numerator{fi1.numerator * fi2.numerator};
    int denominator{fi1.denominator * fi2.denominator};
    result = std::to_string(numerator) + "/" + std::to_string(denominator);
    return result;
}

int main()
{
    FractionItem fi1{getFraction()};
    FractionItem fi2{getFraction()};
    std::cout << "Your fractions multiplied together:" << returnFraction(fi1, fi2) << '\n';

    return 0;
}
