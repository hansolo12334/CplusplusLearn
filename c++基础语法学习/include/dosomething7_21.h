#ifndef DOSOMETHING7_21_H
#define DOSOMETHING7_21_H

#include<iostream>

namespace Foo
{
    int dosomthing(int x,int y);

    void print();


} // namespace Foo

namespace Hh //命名空间嵌套
{
    namespace Ll
    {
        void print();

    } // namespace ll

} // namespace hh

namespace Koo::Soo
{
    int add(int x, int y);
}

#endif
