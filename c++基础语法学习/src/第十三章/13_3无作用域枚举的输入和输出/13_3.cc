#include<iostream>
#include<string>
#include<cstdint> //for int8_t

//当我们定义一个枚举器时，每个枚举器都会根据其在枚举器列表中的位置自动分配一个整数值。
// 默认情况下，第一个枚举器被分配整数值 0 ，并且每个后续枚举器的值都比前一个枚举器大1

//但是也可以这样：
enum Animal
{
    cat = -2, //让cat从-2开始
    dog,      //dog就变成了 -1
    pig,      //pig就变成了0
    horse=4,
    giraffe=5, //和horse共享同一个值
    chicken,    //chicken变成了6
};
//但是 我们应该 避免为枚举器分配显式值


//使用运算符重载 来教 operator << 来打印程序定义的枚举值
std::ostream& operator<<(std::ostream &out, Animal ani)
{
    switch (ani)
    {
    case cat:
        return out << "cat";
    case dog:
        return out << "dog";
    case pig:
        return out << "pig";
    case horse:
        return out << "horse";
    case giraffe:
        return out << "giraffe";
    case chicken:
        return out << "chicken";
    default:
        return out << "??";

    }
}


//可以指定枚举的基本类型
enum Color : std::int8_t
{
    black,
    red,
    blue,
};



int main()
{
    Animal ani{dog};
    std::cout << "ani是: " << ani << '\n';

    std::cout << "动物是: " << Animal::horse << '\n';
    std::cout << "动物是: " << Animal::giraffe << '\n';
    std::cout << "动物是: " << Animal::chicken << '\n';

//枚举大小和基本类型
    Color c{red};
    std::cout << sizeof(c) << '\n';
    //整数到无作用域枚举器的转换
    //c = 2; //报错：invalid conversion from ‘int’ to ‘Color’ [-fpermissive]

    //可以这样 用static_cast
    c = static_cast<Color>(2);


    return 0;
}
