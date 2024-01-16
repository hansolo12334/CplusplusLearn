#include<array>
#include<vector>
#include<iostream>

// 为啥有时候不用vector动态数组?
// 如果需要一个固定的数组 常量 vector性能略低于array


//因此 array 用在 constexpr 数组
// vector 用在 非 constexpr 数组
int main()
{
    // array 的声明， 有两个参数模板 第一个是元素类型
    // 第二个是 数组长度
    std::array<int, 5> a{};
    //对比 vector的声明
    std::vector<int> b(5);

    //array的长度必须是常量表达式:
    // 可以是 整数  constexpr 或者无作用域枚举器
    constexpr int size{3};
    std::array<int, size> c{};

    enum Colors
    {
        red,
        blue,
        max_size
    };
    std::array<int, max_size> d{};

    //运行时常量和 非常量变量不能用于长度
    // 总之就是 array的长度必须在编译器编译时就的知道
    // 运行时再确定时不行的

    // array 可以是 const constexpr
    const std::array<int, 3> c_a{};


    // ! 尽可能的将 std::array 定义为 constexpr
    constexpr std::array<int, 3> c_b{};
    // 否则 就还是 用std::vector吧。。。

    return 0;
}
