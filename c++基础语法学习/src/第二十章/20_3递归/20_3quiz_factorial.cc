#include<iostream>


//递归计算阶乘
int factorial(int n)
{
    if(n<=0){
        return 1;
    }

    return factorial(n - 1) * n;
}


int main()
{
    for (int i = 0; i < 7;i++){
        std::cout << factorial(i) << ' ';
    }
    std::cout << '\n';
    return 0;
}
