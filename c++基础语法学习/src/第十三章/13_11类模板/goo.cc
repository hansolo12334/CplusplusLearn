#include "pair.h"
#include<iostream>


void goo()
{
    hansolo::pair<int> ppp{2, 99};
    std::cout << hansolo::max(ppp) << '\n';
}
