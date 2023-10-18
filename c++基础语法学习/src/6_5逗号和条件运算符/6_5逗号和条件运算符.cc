#include<iostream>
using namespace std;

int main()
{
    //逗号 ,  x,y 先求值x然后y，返回值y
    int x{4};
    int y{6};
    cout << (x++, ++y) << '\n';
    cout << x++ << '\n';

    //条件运算符 ?:  c? x:y  一种特殊的if else

    cout << "条件运算符 " << ((x < y) ? x : y) << '\n';



    return 0;

}
