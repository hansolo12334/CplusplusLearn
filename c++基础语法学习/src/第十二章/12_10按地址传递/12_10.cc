#include<iostream>
#include <string>
#include<cassert>


//!!!多数可以通过地址传递完成的事情都可以通过其他方法更好地完成。遵循这个共同的格言：“尽可能通过引用传递，在必须通过地址传递”


//按值传递
void printByValue(std::string val) // 函数复制了一次string
{
    std::cout << val << '\n'; // print the value via the copy
}
//按引用传递
void printByReference(std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
    ref = {"ref改变值！"};
}
//按地址传递
void printByAddress(std::string *ptr) //ptr获取str的地址
{
    //使用断言判断ptr是否为空
    assert(ptr);
    if (!ptr) //或使用if 检查ptr是否为空
    {
        return;
    }
    std::cout << *ptr << '\n';
    *ptr = "ptr改变值!";
}
//按地址传递不会复制所指向的对象
//按地址传递允许函数修改参数的值
//如果函数不应该修改要传入的对象，则可以使函数参数成为指向 const 的指针：
/*
void printByAddress_const(const std::string *ptr) //ptr获取str的地址
{
    std::cout << *ptr << '\n';
    *ptr = "改变值!";//报错
    //no match for ‘operator=’ (operand types are ‘const std::string’ {aka ‘const std::__cxx11::basic_string<char>’} and ‘const char [11]’)
}
*/
int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // 通过引用来传递str ,不复制

    printByAddress(&str);//传入str的地址

    std::cout << str << '\n';
}
