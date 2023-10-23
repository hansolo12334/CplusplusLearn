#include<iostream>

int main()
{
    //整型文字
    std::cout << 5 << '\n';
    std::cout << 5L << '\n';
    std::cout << 5u << '\n';

    int a{5};
    unsigned int b{6};
    long c{7};

    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';

    float f{4.1f};
    double avogadro { 6.02e23 };
    std::cout << avogadro << '\n';


    char mystring[4]{"as"};
    //mystring = 'a';
    std::cout << *(mystring+1) << '\n';



    return 0;
}
