#include<iostream>
#include<cstddef>




int main()
{
    std::cout << "输入一个正数: ";
    std::size_t length{};
    std::cin >> length;

    int *array{new int[length]{}};

    array[0] = 3;

    array[length-1] = 2;

    std::cout << array[0] << '\n';

    // 必须使用 delete的数组版本 来删除数组  delete[]
    delete[] array;


    // 初始化动态分配数组

    int *array1{new int[3]{1, 3, 4}};

    return 0;
}
