#include<iostream>


//Q 编写一个程序，要求用户输入两个整数，一个命名，另一个命名 smaller larger 。
//  如果用户为第二个整数输入较小的值，请使用块和临时变量来交换较小的和较大的值。然后打印 和 smaller larger 变量的值。
//  在代码中添加注释，指示每个变量的死亡位置。
//  注意：打印值时，应保留较小的输入和 larger 较大的输入， smaller 无论输入的顺序如何。


int main()
{
    int smaller{};
    int larger{};
    std::cout << "Enter an integer:";
    std::cin >> smaller;
    std::cout << "Enter an larger integer:";
    std::cin >> larger;

    if (smaller>larger)//或者可以使用 std::swap(smaller , larger)
    {
        std::cout << "Swapping the values\n";
        int temp{smaller};
        smaller = larger;
        larger = temp;
    } //temp 在这里死亡

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
}

//Q 变量的范围、持续时间和生存期之间有什么区别？
//  默认情况下，局部变量具有什么样的范围和持续时间（以及这些含义）？

//A 变量的作用域决定了变量的可访问位置。持续时间定义控制何时创建和销毁变量的规则。
//  变量的生存期是其创建和销毁之间的实际时间
//  局部变量具有块范围，这意味着可以在定义它们的块内访问它们
//  局部变量具有自动持续时间，这意味着它们在定义点创建，并在定义它们的块末尾销毁
