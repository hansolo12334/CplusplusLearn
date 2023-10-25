#include<iostream>

//C++模板

/*
C++支持3种不同类型的模板参数：
1.类型模板参数（其中模板参数表示类型）
2.非类型模板参数（其中模板参数表示 constexpr 值）
3.模板模板参数（其中模板参数表示模板）
*/


//使用单个大写字母（以 开头 T ）命名类型模板参数（例如、 T 、 U V 等...）


// 在此上下文中， typename 和 class 关键字之间没有区别。您经常会看到人们使用该关键字class，  因为它之前已引入该语言。
// 但是，我们更喜欢较新的 typename 关键字，因为它更清楚地表明类型模板参数可以替换为任何类型（例如基本类型），而不仅仅是类类型。

//template<class T> 也可以
template<typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(1, 2) << '\n';
    return 0;
}
