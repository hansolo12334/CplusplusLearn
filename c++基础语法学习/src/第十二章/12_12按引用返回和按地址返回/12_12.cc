#include<iostream>
#include <string>
#include<cassert>


//通过引用返回的对象必须在函数返回后 存在
// 使用引用返回有一个主要警告：
// 程序员必须确保被引用的对象比返回引用的函数活下去。
// 否则，返回的引用将悬而未决（引用已销毁的对象），并且使用该引用将导致未定义的行为。

const std::string &getProgramName()
{
    static const std::string programName{"hansolo"};
    //static 具有持续静态时间 让programName持续到整个程序结束
    return programName;
}

const std::string &getProgramName1()
{
    const std::string programName{"hansolo"};
    //mei
    return programName;
}


//生存期延长无法跨功能边界工作(Lifetime extension doesn’t work across function boundaries)

//不要通过引用返回非常量局部静态变量


int main()
{
    int x{2};

    std::cout << getProgramName() << '\n';
    //std::cout << getProgramName1() << '\n';
    //报错 ：Segmentation fault
    //此程序的结果未定义。返回时 getProgramName1() ，将返回绑定到局部变量 programName 的引用。然后，因为是一个具有自动持续时间的局部变量， programName 在 programName 函数结束时被销毁。这意味着返回的引用现在悬而未决，并且在 main() 函数中使用 会导致 programName 未定义的行为。

    return 0;
}
