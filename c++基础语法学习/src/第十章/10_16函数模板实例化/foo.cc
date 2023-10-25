#include "max.h" // import template definition for max<T>(T, T)
#include <iostream>

void foo()
{
	std::cout << max(3, 2) << '\n';
}


//模板函数在cpp文件前向声明不行 不能调用
template<typename V>
void goo(V x)
{
    std::cout << "goo: " << x << '\n';
}
