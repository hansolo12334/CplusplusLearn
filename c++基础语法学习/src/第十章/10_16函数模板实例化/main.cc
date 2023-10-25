#include "max.h" // import template definition for max<T>(T, T)
#include <iostream>

void foo(); // forward declaration for function foo

int main()
{
    std::cout << max(3, 5) << '\n';
    foo();

    //goo(3); //error: ‘goo’ was not declared in this scope;
    // g++ main.cc foo.cc -I /home/hansolo/CplusplusLearn/c++基础语法学习/src/第十章/10_16函数模板实例化/include/  -g -v -o main
    return 0;
}
