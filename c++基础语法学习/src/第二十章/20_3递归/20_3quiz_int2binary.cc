#include<iostream>


//递归计算 整数中每个数字的总和
void int2binary(unsigned int n)
{


    if (n> 1)
    {
        int2binary(n / 2);
    }

    std::cout << n % 2;
}


int main()
{
    int2binary(14);
    std::cout << '\n';



    int2binary(static_cast<unsigned int>(-14));

    std::cout << '\n';
    return 0;
}
