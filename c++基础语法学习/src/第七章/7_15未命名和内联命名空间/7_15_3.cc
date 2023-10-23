#include <iostream>

//命名空间可以是内联的，也可以是未命名的


//在这种情况下，最好将匿名命名空间嵌套在内联命名空间中。这具有相同的效果（默认情况下，匿名命名空间内的所有函数都具有内部链接），但仍会为您提供可以使用的显式命名空间名称

namespace V1 // declare a normal namespace named V1
{
    void doSomething()
    {
        std::cout << "V1\n";
    }
}


// inline namespace // declare an inline unnamed namespace
// {
//     void doSomething() // has internal linkage
//     {
//         std::cout << "V2\n";
//     }
// }
//                |
//                |
//                |
//               \/

inline namespace V2 // declare an inline namespace named V2
{
    namespace // unnamed namespace
    {
        void doSomething() // has internal linkage
        {
            std::cout << "V2\n";
        }

    }
}

int main()
{
    V1::doSomething(); // calls the V1 version of doSomething()
    V2::doSomething(); // calls the V2 version of doSomething()

    ::doSomething(); // calls the inline version of doSomething() (which is V2)

    return 0;
}
