#include<iostream>
#include"dosomething.h"

#define HANSOLO "hansolo"
#define HAN std::cout << "han\n";


template<typename T>
T getSum(T a,T b)
{
    return a + b;
}

void doSomething(int /*count*/)
{
    std::cout << "not use value\n";
}

int main()
{
    int a = 1;
    int b = 2;
    std::cout << getSum(a, b) << "\n";
    std::string aa = "ssss";
    std::string bb = "dddd";
    std::cout << getSum(aa, bb) << "\n";
    doSomething(4);


    HAN
    //条件编译
    #ifdef HANSOLO
    std::cout << HANSOLO << "\n";
    #endif

    #ifndef HANBO
    std::cout << "HANBO NOT DEFINE\n";
    #endif





    //一种新的注释方法
    #if 0
    std::cout<<"wil not be print\n";
    #endif

    #if 1
    std::cout<<"wil  be print\n";
    #endif

    #if 1

    #if 0
    std::cout<<"wil  be print\n";
    #endif

    #if 1
    std::cout<<"print!\n";
    #endif

    #endif

    int result{dothing(5, 6)};
    std::cout << result << "\n";


    return 0;
}
