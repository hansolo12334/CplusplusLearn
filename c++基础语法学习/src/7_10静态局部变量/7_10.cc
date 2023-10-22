#include<iostream>

// 探讨 static 关键字在应用于局部变量时的用法
// 静态局部变量
// 避免使用 static 局部变量，除非变量永远不需要重置


//自动持续时间（默认）
void incrementAndPrint_automatic()
{
    int s_value{1};
    ++s_value;
    std::cout << s_value << '\n';
}//value在此销毁


//现在考虑使用静态局部变量的该程序版本。此程序与上述程序之间的唯一区别是，我们已使用 static 关键字将局部变量从 automatic duration 更改为 static duration
void incrementAndPrint_static()
{
    static int s_value{1};//在变量前加前缀s_ 来表示静态变量
    static int s_value1{};
    --s_value1;
    ++s_value;
    std::cout << s_value1 << '\n';
}
/*
    在此程序中，由于已声明为 static ，因此 s_value 在程序启动时创建

    初始化为零或具有 constexpr 初始值设定项的静态局部变量可以在程序启动时初始化

    没有初始值设定项或非 constexpr 初始值设定项的静态局部变量在程序启动时初始化为零。
    具有非 constexpr 初始值设定项的静态局部变量在第一次遇到变量定义时重新初始化。
    在后续调用中会跳过该定义，因此不会发生进一步的重新初始化。由于它们具有静态持续时间，因此未显式初始化的静态局部变量默认为零初始化

    Because s_value has constexpr initializer 1, s_value will be initialized at program start
    When s_value goes out of scope at the end of the function, it is not destroyed. Each time the function incrementAndPrint() is called, the value of s_value remains at whatever we left it at previously. Consequently, this program outputs:

*/


/*
    静态持续时间局部变量最常见的用途之一是唯一 ID 生成器。想象一个程序，你有许多类似的对象（例如，一个游戏，你被许多僵尸攻击，或者一个模拟，你显示许多三角形）。如果您发现缺陷，几乎不可能区分哪个对象有问题。但是，如果在创建时为每个对象指定一个唯一标识符，则可以更轻松地区分这些对象以进行进一步调试

*/
int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}
// 第一次调用此函数时，它返回 0。第二次，它返回 1。每次调用它时，它都会返回比上次调用它时高的数字 1。您可以将这些编号指定为对象的唯一 ID。因为是局部变量，所以 s_itemID 不能被其他函数“篡改”


// 初始化静态局部变量。静态局部变量仅在第一次执行代码时初始化，而不是在后续调用时初始化。


int main()
{
    incrementAndPrint_automatic();
    incrementAndPrint_automatic();
    incrementAndPrint_automatic();

    std::cout << '\n';
    incrementAndPrint_static();
    incrementAndPrint_static();
    incrementAndPrint_static();
    return 0;
}
