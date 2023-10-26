#include<iostream>


int main()
{
    int x{5};
    int *ptr{&x};//ptr指向了x 的地址

    int y{6};
    ptr = &y; //ptr现在又指向了y的地址

    *ptr = 7; //*ptr 和 y 的值都变成了 7

    const int z{5};
    /*
    指向常量值的指针
    int *ptrz{&z};
    报错 nvalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
    若要声明指向 const 值的指针，请在指针的数据类型之前使用该 const 关键字：
    */
    const int *ptr1{&z};
    //由于指向 const 的指针本身不是 const（它只指向 const 值），我们可以通过为指针分配一个新地址来更改指针指向的内容：
    const int g{7};
    ptr1 = &g;

    //就像对 const 的引用一样，指向 const 的指针也可以指向非 const 变量。
    //指向 const 的指针将指向的值视为常量，而不管该地址处的对象最初是否定义为 const：
    const int *ptr2{&x};
    //*ptr2 = 2;
    //报错 error: assignment of read-only location ‘* ptr2
    //ptr2 指向了一个 const int , 因此不能 通过ptr2改变const int 的值
    x = 9;//但这是允许的 因为 x是一个非常量 当通过非常量 标识符x访问时



    //和上面不同！
    //常量指针 const pointer

    //我们也可以使指针本身常量。const 指针是初始化后无法更改地址的指针。

     //若要声明 const 指针，请在指针声明中的星号后使用 const 关键字：
    int *const ptr4{&x};

    //在上述情况下， ptr4 是一个指向（非常量）int 值的常量指针。
    //就像普通的 const 变量一样，const 指针必须在定义时初始化，并且此值不能通过赋值更改：
    //ptr4 = &y; //报错 一旦初始化 ptr4指针就不能改变了

    *ptr4 = 3; //但是 ptr4指向的 x 是 非常量变量 可以改变
    std::cout << x << '\n'; //这里 x变成了 3

    return 0;
}
