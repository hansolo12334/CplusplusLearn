#include <iostream>
#include "constants.h"

// 编写一个名为 constants.h 的文件，该文件使以下程序运行。如果您的编译器支持 C++17，请使用内联 constexpr 变量。否则，请使用正常的 constexpr 变量。 max_class_size 应该是 35 .

int main()
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;


	if (students > constants::max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large";

	return 0;
}
