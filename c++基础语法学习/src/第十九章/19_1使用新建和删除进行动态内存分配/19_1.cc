#include<iostream>



// 使用 new 运算符 来动态分配 单个变量


int main()
{
    //从操作系统请求整数的内存。new 运算符使用该内存创建对象，然后返回一个 指针 ，其中包含已分配的内存的地址
    int *ptr{new int};
    *ptr = 3;

    //在动态分配变量时 也可以直接初始化


    int *ptr1{new int{3}}; //使用统一初始化
    int *ptr2{new int(4)};//使用直接初始化

    int *ptr3{ptr}; //指向了和ptr同一个内存
    int *ptr4 = ptr; //指向了和ptr同一个内存

    delete ptr;// 导致 ptr3 ptr4 悬空
    //将已删除的指针设置为 nullptr，除非它们之后立即超出范围
    // ptr = nullptr;
    return 0;
}
