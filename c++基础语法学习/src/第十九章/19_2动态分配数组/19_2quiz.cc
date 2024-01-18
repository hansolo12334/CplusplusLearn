#include<iostream>
#include<cstddef>
#include<string>
#include<algorithm>

bool sortByAlhapbet(std::string a, std::string b)
{
    return a[0] <b[0];
}
int main()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t length{};
    std::cin >> length;

    std::string *array{new std::string[length]{}};

    for (auto i = 0; i < length;i++)
    {
        std::cout << "Enter name #" << i << ": ";
        std::string name;
        std::cin >> name;
        array[i] = name;
    }

    std::sort(array, array+length,sortByAlhapbet);


    std::cout << "Here is your sort list:\n";
    for (auto i = 0; i < length; i++)
    {
        std::cout << "Name #" << i << ": " << array[i] << '\n';
    }

    delete[] array;
    return 0;
}
