#include<iostream>


//递归计算 整数中每个数字的总和
int sum(int n)
{
    if (n < 10)
    {
        return n;
    }

    return sum(n / 10)+n%10;
}


int main()
{
    std::cout <<sum(93427)<< '\n';
    return 0;
}
