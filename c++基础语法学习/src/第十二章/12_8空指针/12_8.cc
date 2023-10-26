#include <iostream>


//空指针

/*
!!!!!!!每当使用指针时，都需要格外小心，确保代码不要取消引用 null 或悬空指针，因为这会导致未定义的行为（可能是应用程序崩溃）。
*/


int main()
{
    int *ptr{};//空指针

    //nullptr 关键字
    // 与关键字 true false 非常相似，表示布尔文本值，
    // nullptr 关键字表示空指针文本。
    // 我们可以用来 nullptr 显式初始化或为指针分配一个空值
    int *ptr2{nullptr};

    std::cout << ptr << '\n';


    /*
    std::cout << *ptr << '\n';
    取消引用空指针会导致未定义的行为 编译器输出:  Segmentation fault
    */





    std::cout << ptr2 << '\n';

    int x{2};

    ptr = &x;
    std::cout << *ptr << '\n';


    //检查空指针：
    if (ptr2==nullptr)
    {
        std::cout << "ptr2是空指针\n";
    }
    else
    {
        std::cout << "ptr2是非空指针\n";
    }
    std::cout << ((ptr == nullptr) ? "ptr是非空指针\n" : "ptr是空指针\n");

    return 0;
}


// 使用 nullptr 避免悬空指针
