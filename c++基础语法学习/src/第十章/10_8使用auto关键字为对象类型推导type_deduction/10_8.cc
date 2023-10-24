#include<iostream>


int main()
{
    //初始化变量的类型推导
    // 类型推断（有时也称为类型推断）是一种功能，它允许编译器从对象的初始值设定项推断对象的类型。
    // 要使用类型推断，使用 auto 关键字代替变量的类型:
    auto d{5.0};   //自动推导为double
    auto i{1 + 3}; //自动推导为int
    auto x{i};     //自动推导为int

    /*
    //类型推断不适用于没有初始值设定项或空初始值设定项的对象。因此，以下内容无效：
    auto a;   // x error: direct-list-initialization of ‘auto’ requires exactly one element [-fpermissive]
    auto b{}; // x error: direct-list-initialization of ‘auto’ requires exactly one element [-fpermissive]
    */

    //类型推导 会丢弃 const/constexpr关键字
    const int a{2};
    auto b{a};

    std::cout << typeid(b).name() << '\n'; //输出 i int而不是const int

    //如果想要const:
    const auto c{a};


    //
    auto ss{"hansolo"}; //得到的不是 std::string 而是 char const*
    std::cout << typeid(ss).name() << '\n';
    //在终端输入 g++ 10_8.cc 得到 a.out
    //执行a.out:
    // ./a.out | c++filt --type
    //得到：
    /*
    int
    char const*
    */
   //如果像的得到std::string:
    using namespace std::literals; // easiest way to access the s and sv suffixes
    auto sss{"hansolo"s};
    auto ssss{"hansolo"sv};
    std::cout << typeid(sss).name() << '\n';
    //得到 std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >
    std::cout << typeid(ssss).name() << '\n';
    //得到 std::basic_string_view<char, std::char_traits<char> >
}
