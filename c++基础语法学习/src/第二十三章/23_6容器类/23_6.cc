#include <iostream>
#include "IntArray.h"

/*
 一些可以/应该进行的额外改进：首先，我们可以将其设置为模板类，以便它可以与任何可复制类型一起使用，而不仅仅是 int。
 其次，我们应该添加各种成员函数的 const 重载，以正确支持 const IntArrays。
 第三，我们应该添加对移动语义的支持或禁用移动语义（通过添加或删除移动构造函数和移动赋值）。
*/

int main()
{
    // Declare an array with 10 elements
    IntArray array(10);

    // Fill the array with numbers 1 through 10
    for (int i{ 0 }; i<10; ++i)
        array[i] = i+1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);

    // Remove the element with index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // A few more tests to ensure copy constructing / assigning arrays
    // doesn't break things
    {
        IntArray b{ array };
        b = array;
        b = b;
        array = array;
    }

    // Print out all the numbers
    for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    return 0;
}
