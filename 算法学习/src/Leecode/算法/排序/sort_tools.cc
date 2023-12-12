#include<random>
#include<iostream>

unsigned int getRandomDeviceValue()
{
    std::random_device rd{};
    return rd();
}

std::vector<int> generate_unifrom_random(int min, int max,int size)
{
    std::vector<int> input{};
    std::mt19937 mt{getRandomDeviceValue()};
    std::uniform_int_distribution die6{min, max};
    for (int i = 0; i < size;i++)
    {
        input.push_back(die6(mt));
    }
    return input;
}

void printVector(std::vector<int> &v)
{
    for (int i:v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
