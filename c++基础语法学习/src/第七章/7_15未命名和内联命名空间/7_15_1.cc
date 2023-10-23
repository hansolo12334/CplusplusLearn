#include<iostream>

/*
假设您对 不 doSomething() 满意，并且希望以某种方式改进它，从而改变它的行为方式。但是，如果这样做，则可能会破坏使用旧版本的现有程序。你是如何处理的？

一种方法是使用不同的名称创建函数的新版本。但是在许多更改过程中，您最终可能会得到一整套几乎相同名称的函数（ doSomething 、、 doSomething_v2 、 doSomething_v3 等...）

另一种方法是使用内联命名空间。内联命名空间是通常用于对内容进行版本控制的命名空间。与未命名命名空间非常相似，在内联命名空间中声明的任何内容都被视为父命名空间的一部分。但是，与未命名的命名空间不同，内联命名空间不会影响链接。

为了定义内联命名空间，我们使用 inline 关键字：
*/

inline namespace V1 // declare an inline namespace named V1
{
    void doSomething()
    {
        std::cout << "V1\n";
    }
}

namespace V2 // declare a normal namespace named V2
{
    void doSomething()
    {
        std::cout << "V2\n";
    }
}

int main()
{
    V1::doSomething(); //调用V1版本的doSomething()
    V2::doSomething(); //调用V2版本的doSomething()

    doSomething(); //调用inline版本的 doSomething() V1的

    return 0;
}
