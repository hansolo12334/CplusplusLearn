#include<iostream>
#include<cassert>

// 在接受参数的函数中，调用方可能能够传入语法上有效但在语义上毫无意义的参数。
// 使用条件语句来检测无效参数（或验证某种其他类型的假设），以及打印错误消息和终止程序，是检测问题的常用方法，C++提供了执行此操作的快捷方式。
void printDivision(int x,int y)
{
    if (y not_eq 0)
    {
        std::cout << static_cast<double>(x) / y;
    }
    else
    {
        std::cout << "零不能做除数!\n";
    }
}

void printDivision1(int x,int y)
{
    assert(y != 0 && "零不能做除数!");
    std::cout << static_cast<double>(x) / y<<'\n';
}

/*
C++还有另一种类型的断言，称为 static_assert 。static_assert是在编译时而不是运行时检查的断言，失败 static_assert 会导致编译错误。与在标头中声明的 assert 不同，static_assert 是一个关键字，因此无需包含标头即可使用它。
*/

static_assert(sizeof(long) == 8, "long 类型必须 8字节");

int main()
{
    printDivision1(1, 1);
    return 0;
}
