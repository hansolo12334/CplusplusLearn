#include<iostream>


enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal ani)
{
    using enum Animal;
    switch (ani)
    {
    case pig:
        return "pig";
    case chicken:
        return "chicken";
    case goat:
        return "goat";
    case cat:
        return "cat";
    case dog:
        return "dog";
    case duck:
        return "duck";
    default:
        return "???";
    }
}

void printNumberOfLegs(Animal ani)
{
    std::cout << "A " << getAnimalName(ani) << " has ";
    using enum Animal;
    switch (ani)
    {
    case pig:
    case goat:
    case dog:
    case cat:
        std::cout << "4";
        break;

    case chicken:
    case duck:
        std::cout << "2";
        break;
    default:
        std::cout << "???";
        break;
    }
    std::cout << " legs\n";
}

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);
    return 0;
}
