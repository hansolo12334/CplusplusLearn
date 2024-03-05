#include<iostream>


/*C++内存分配为几个区：
    栈
    堆
    全局/静态储存区
    常量储存区
    代码区
*/




int main()
{
    // 堆段 跟踪用于动态内存分配的内存
    int *ptr = new int{};
    int *array = new int[10]{};
    //删除动态分配的变量时，内存将“返回”到堆中，然后在收到将来的分配请求时可以重新分配内存。请记住，删除指针不会删除变量，它只是将关联地址处的内存返回给操作系统。
    *array = 1;
    *(array + 1) = 2;
    std::cout << *array << '\n';

    //调用栈（call stack）


}
