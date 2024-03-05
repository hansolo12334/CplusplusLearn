#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>
#include <functional>


//使用 lambda 创建时 std::function ， std::function 内部会创建 lambda 对象的副本。因此，我们对 的 func() 调用实际上是在 lambda 的副本上执行的，而不是实际的 lambda。
void myInvoke(const std::function<void()> &func)
{
    func();
}


int main()
{
    int i{0};
    auto count = [i]() mutable { std::cout << ++i << '\n'; };

    myInvoke(count);
    myInvoke(count);
    myInvoke(count);


    myInvoke(std::ref(count));
    myInvoke(std::ref(count));
    myInvoke(std::ref(count));

    return 0;
}
