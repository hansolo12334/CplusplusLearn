#include<iostream>


/*
编写一个名为 calculate（） 的函数，该函数采用两个整数和一个表示以下数学运算之一的字符：+、-、*、/ 或 %（余数）。使用 switch 语句对整数执行适当的数学运算，并返回结果。如果将无效运算符传递到函数中，则该函数应打印错误消息。对于除法运算符，做一个整数除法，不用担心除以零。
*/

int calculate(int x,int y,char symbol)
{
    using std::cout;
    int result{0};
    switch (symbol)
    {
    case '+':
        cout << "x + y = " << x + y << '\n';
        return  x + y;
        //break;
    case '-':
        cout << "x - y = " << x - y << '\n';
        //return = x + y;
        return  x - y;
        //break;
    case '*':
        cout << "x * y = " << x * y << '\n';
        return  x * y ;
        //break;
    case '/':
        cout << "x / y = " << x / y << '\n';
        return x / y;
        // break;
    case '%':
        cout << "x % y = " << x % y << '\n';
        return x % y;
    default:
        cout << "不存在该运算符!\n";
        return 0;
    }
}


int main()
{
    int x{};
    int y{};
    char symbol{};
    std::cout << "输入一个整数:";
    std::cin >> x;
    std::cout << "输入另一个整数:";
    std::cin >> y;
    std::cout << "输入一个数学符号:";
    std::cin >> symbol;
    std::cout << "result: " << calculate(x, y, symbol) << '\n';
    return 0;
}
