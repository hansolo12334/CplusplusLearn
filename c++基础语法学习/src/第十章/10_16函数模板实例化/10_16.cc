#include<iostream>



template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}


//具有非模板参数的函数模板
template <typename T>
int somefuc(T x, double y)
{
    return 2;
}

int main()
{
    //实例化
    //max<actual_type>(arg1， arg2);
    // actual_type是一些实际类型，如 int 或 double 指定类型

    std::cout << max<int>(1,4) << '\n';
    std::cout << max<double>(1.1,4.4) << '\n';

    //或者让编译器自己推导
    std::cout << max<>(1.1,4.4) << '\n';
    std::cout << max(1,4) << '\n';

    std::cout << typeid("hello").name() << '\n'; //char [6]
    return 0;
}

//泛型编程 generic programming
//由于模板类型可以替换为任何实际类型，因此模板类型有时称为 泛型类型 。
//由于模板可以不可知地编写特定类型，因此使用模板进行编程有时称为 泛型编程 。
//虽然C++通常非常关注类型和类型检查，但相比之下，泛型编程让我们专注于算法的逻辑和数据结构的设计，而不必担心类型信息
