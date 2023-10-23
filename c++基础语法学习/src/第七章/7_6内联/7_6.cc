#include<iostream>

[[maybe_unused]] static int x{9};
int main()
{

    {
        static int x{2};
    }
    std::cout << x << '\n';

}
