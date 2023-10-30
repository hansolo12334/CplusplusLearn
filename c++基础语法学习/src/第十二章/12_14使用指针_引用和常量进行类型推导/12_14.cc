#include<iostream>
#include <string>
#include<cassert>


//类型推导会 丢弃 const 和 constexpr关键字

//类型推导会 丢弃 引用 &

std::string& getRef();
auto ref{getRef()}; //推导为std::string 而不是 std::string&
//如果还想推导为 引用 的话 就在前面自己加上
auto &ref1{getRef()};


//顶级常量和低级常量：
//顶级常量
//顶级常量是适用于对象本身的常量限定符
const int x;
int *const ptr; // 指针本身是const

//低级常量
//低级 const 是适用于被引用或指向的对象的 const 限定符：
const int &ref;
const int *ptr1; //指针指向const对象

//对常量值的引用始终是低级常量。指针可以具有顶级、低级或两种类型的常量：
const int *const ptr3;//左侧的const是低级，右侧的const是高级


//常量推导和常量引用
//与引用不同，类型推导不会删除指针：

std::string *getPtr();

// 类型推导和指针
// 与引用不同，类型推导不会删除指针：
auto ptr1{getPtr()};
//我们还可以将星号与指针类型推导结合使用：
auto* ptr2{ getPtr() };
//auto 和 auto* 的区别

int main()
{

}
