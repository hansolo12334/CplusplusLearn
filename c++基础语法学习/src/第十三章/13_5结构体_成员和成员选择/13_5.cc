#include <iostream>

//聚合 aggregate:
//在一般编程中，聚合数据类型（也称为聚合）是可以包含多个数据成员的任何类型。
//某些类型的聚合允许成员具有不同的类型（例如结构），
//而其他类型的聚合则要求所有成员必须属于单一类型（例如数组）。
//在 C++ 中，聚合的定义更窄，也更复杂
/*
若要成为 C++ 中的聚合，类型必须满足以下条件：
 是类类型（结构、类或联合），还是数组类型（内置数组或 std::array ）。
 没有私有或受保护的非静态数据成员
 没有用户声明或继承的构造函数
 没有基类
 没有虚拟成员函数
*/

struct Emplyee
{
    int id{};
    int age{};
    double wage{};
};


int main()
{

    Emplyee han{};
    han.age = 22;

    //初始化
    Emplyee solo{2,23,10000.0};//使用有括号列表进行列表初始化
    Emplyee jack(3, 21, 10000.0);//使用括号列表直接初始化
    //按照结构体里面的顺序初始化
    //如果是这样
    Emplyee tom{2, 34};//则tom.wage就被初始化为0


    std::cout << han.age << '\n';
    std::cout << jack.age << '\n';
    std::cout << tom.wage << '\n';

    //const 结构体
    const Emplyee john{};
    constexpr Emplyee Miller{};

    //在c++20中 可以这样初始化结构体 按照顺序初始
    Emplyee Mark{.id = 4, .age = 34, .wage = 33000};
    Emplyee Tom{.id{5}, .age{22}, .wage{30000}};
    std::cout << Tom.age << '\n';
    //甚至可以使用另一个同类型的结构体初始化一个结构体
    Emplyee Hank{Tom};
    std::cout << Hank.age << '\n';
    return 0;
}
