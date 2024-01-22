#include<iostream>


using addFunction = int (*)(int, int);

int test_using_function(int x, int y, addFunction pfun);

int foo()
{
    return 2;
}


int add(int x,int y)
{
    return x + y;
}
int multiply(int x,int y)
{
    return x * y;
}
int reduce(int x,int y)
{
    return x - y;
}

int doSomeThing(int x,int y,int(*something)(int,int))
{
    return something(x, y);
}

double divide(int x,int y)
{
    return static_cast<double>(x) / static_cast<double>(y);
}


                                        //甚至提供默认值 默认功能
void praseCallback(int x, int y, double(*something)(int, int)=divide)
{
    std::cout << something(x, y) << '\n';
};

int main()
{
    //会发生什么？
    // std::cout << foo << '\n';


    //强制打印出 foo的地址
    std::cout << reinterpret_cast<void *>(foo) << '\n';


    //使用函数指针最有用的事情之一是将一个函数作为参数传递给另一个函数。用作另一个函数参数的函数有时称为回调函数。

    //
    int (*add_new)(int, int) {&add};

    std::cout << add_new(1, 2) << '\n';

    //作为回调函数 这样用
    std::cout << doSomeThing(4, 1, add) << '\n';
    std::cout << doSomeThing(4, 2, multiply) << '\n';
    std::cout << doSomeThing(4, 1, reduce) << '\n';


    praseCallback(2, 3, divide);
    praseCallback(2, 5);

    //  int (*add_new)(int, int) 很丑？ 可以这样写
    using addFunction = int (*)(int, int);
    // 定义了一个名为 addFunction的类型别名，它指向一个函数的指针，该函数采用两个整数并返回一个int值
    addFunction add_1{add};
    std::cout << add_1(2, 8) << '\n';

    //在函数中 使用类型别名
    std::cout << test_using_function(2, 5, reduce) << '\n';


    return 0;
}

using addFunction = int (*)(int, int);

int test_using_function(int x,int y,addFunction pfun)
{
    return pfun(x, y);
}
