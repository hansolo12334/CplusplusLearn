#include<iostream>


// 1. 基于参数数量的重载

int add(int x,int y)
{
    return x + y;
}
int add(int x,int y,int z)
{
    return x + y + z;
}


// 2. 基于参数类型的重载
// 只要每个重载函数的参数类型列表不同，也可以对函数进行区分
int addd(int x,int y)
{
    return x + y;
}
double addd(double x,double y)  //double double
{
    return x + y;
}
double addd(int x,double y)     //int   double
{
    return x + y;
}

//不考虑函数的返回类型进行区分
/*
int getRandomValue();// note: old declaration ‘int getRandomValue()’
double getRandomValue(); // error: ambiguating new declaration of ‘double getRandomValue()’
*/

int main()
{
    using std::cout;
    cout << add(1, 1) << '\n';
    cout << add(1, 1, 1) << '\n';

    cout << addd(1, 1) << '\n';
    cout << addd(1, 2.0) << '\n';

    return 0;
}
