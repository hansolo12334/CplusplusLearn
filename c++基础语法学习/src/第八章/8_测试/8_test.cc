#include<iostream>
#include<cassert>
#include<cmath>
//素数是大于 1 的自然数，只能被 1 和自身整除（没有余数）。通过使用 for 循环编写 isPrime() 函数来完成以下程序。成功后，程序将打印“成功！

bool isPrime(int x)
{
    if(x==0 or x==1)
    {
        return false;
    }

    for (size_t i = 2; i <= static_cast<int>(std::sqrt(x)); i++)
    //不用遍历到x 只用到sqrt(x)就行
    {

        if (x%i==0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}
