#include <iostream>

// write your add function template here
// Q  编写一个名为的函数模板 add ，允许用户添加 2 个相同类型的值。应运行以下程序：

template<typename T>
T add(T x,T y)
{
    return x + y;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

	return 0;
}
