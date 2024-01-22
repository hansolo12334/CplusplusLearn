#include<iostream>
#include<functional>


//使用 std::functional 标准库

//类型别名 std：：function 有助于提高可读性

using ValidateFunction = std::function<int(int,int)>;
//定义类型别名时，我们必须显式指定任何模板参数。在这种情况下，我们不能使用 CTAD，因为没有初始值设定项来推断模板参数


int add(int x,int y)
{
    return x+y;
}

int foo()
{
    return 5;
}

int goo()
{
    return 6;
}

int main()
{
    std::function<int()> fcnPtr{&foo};
    //现在是foo
    std::cout << fcnPtr() << '\n';

    // 现在是goo
    fcnPtr = &goo;

    std::cout << fcnPtr() << '\n';


    //使用别名
    ValidateFunction fctPtr;
    fctPtr = &add;
    std::cout << fctPtr(2, 5) << '\n';




    //函数指针的类型推断
    //使用 auto自动推导 很方便 但可读性不高 容易出错
    auto autoFucPtr{&add};
    std::cout << autoFucPtr(2, 4) << '\n';

    return 0;
}
