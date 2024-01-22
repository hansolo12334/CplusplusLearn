#include<iostream>
#include<functional>
#include<string>

using namespace std;


using ArithmeticFunction = function<int(int, int)>;


int add(int x,int y)
{
    return x + y;
}

int subtract(int x,int y)
{
    return x - y;
}
int multiply(int x,int y)
{
    return x * y;
}
int divide(int x,int y)
{
    return x / y;
}


ArithmeticFunction getArithmeticFunction(int sb)
{
    switch (sb)
    {
    case '+':
        return add;
    case '-':
        return subtract;
    case '*':
        return multiply;
    case '/':
        return divide;
    default:
        break;
    }
    return nullptr;
}

int main()
{
    cout << "输入一个数: ";
    int x;
    cin >> x;
    cout << "输入另外一个数: ";
    int y;
    cin >> y;
    cout << "输入数学运算符 ('+' '-' '*' '/') :";
    char sb;
    cin >> sb;
    ArithmeticFunction func = getArithmeticFunction(sb);

    if(func)
    {
        cout << func(x, y) << '\n';
    }



    return 0;
}
