#include<iostream>

#include "dosomething7_21.h"
#include "dosomething7_22.h"


//当将两个相同的标识符引入同一范围时，会发生命名冲突，并且编译器无法消除使用哪个标识符的歧义。发生这种情况时，编译器或链接器将产生错误，因为它们没有足够的信息来解决歧义。


void print()
{
    std::cout << "??\n";
}

int main()
{
    std::cout << Foo::dosomthing(1, 2) << '\n';
    std::cout << Goo::dosomthing(1, 2) << '\n';
    Foo::print();
    Goo::print();
    Hh::Ll::print();//嵌套

    ::print();//call 全局命名空间


    //C++允许创建命名空间别名 将一长串命名空间暂时缩短为更短的名称
    namespace Hansolo = Koo::Soo;
    std::cout << Hansolo ::add(1, 2) << '\n';

    return 0;
}
