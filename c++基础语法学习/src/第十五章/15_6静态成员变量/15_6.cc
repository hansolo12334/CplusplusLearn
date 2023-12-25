#include <iostream>
#include <string>
#include<string_view>

//静态成员不与类对象关联
// 静态成员是位于类的作用域区域内的全局变量
// 使用类名和作用域解析运算符 (::) 访问静态成员

struct Something
{
    static int s_value;
};


int Something::s_value{1};


class anotherthing
{
    //此静态成员定义不受访问控制的约束：您可以定义和初始化该值，即使它在类中声明为 private（或受保护）
private:
    static int s_m_value;

public:
    static int s_value;


    //由于静态成员变量是常量 因此不需要显式定义行
    static const int ss_value{2};

    //内联变量 可以在类内初始化 而不管他是不是常量
    // 这是定义和初始化静态成员的首选方法
    static inline int sss_value{4};


    //c++17开始 constexpr 也可以在类定义中初始化 而无需显式的使用inline 关键字
    static constexpr double sc_value{33.0};
    static constexpr std::string_view sc_string{"hansolo"};

    //因此 本节的最佳实践是:
    //让 static 成员是 constexpr或者inline 在类内初始化
};

//定义和初始化静态成员变量 需要在外部全局范围内显式定义
int anotherthing::s_value{1};
int anotherthing::s_m_value{2};

//如果类是在头 （.h） 文件中定义的，则静态成员定义通常放置在该类的关联代码文件中（例如 Something.cpp ）。
//如果类是在源 （.cpp） 文件中定义的，则静态成员定义通常直接放置在类的正下方。
//不要将静态成员定义放在头文件中（与全局变量非常相似，如果该头文件被多次包含，则最终会得到多个定义，这将导致编译错误）。


int main()
{
    Something s1{};
    Something s2{};
    std::cout << s1.s_value << '\n';

    s2.s_value = 2;

    std::cout << s1.s_value << '\n';


    anotherthing::s_value = 2;
    //甚至没有实例化 仍然可以通过类名和作用域解析符:: 访问s_value
    std::cout << anotherthing::s_value << '\n';

    return 0;
}
