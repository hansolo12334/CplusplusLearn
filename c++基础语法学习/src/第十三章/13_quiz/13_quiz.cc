#include<iostream>
#include<string>


enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
};

struct Monster
{
    MonsterType type{};
    std::string name{};
    int damage{};
};



void printMonster(Monster monster)
{
    using enum MonsterType;
    switch (monster.type)
    {
    case ogre:
        std::cout << "This Orge";
        break;
    case dragon:
        std::cout << "This Dragon";
        break;
    case orc:
        std::cout << "This Orc";
        break;
    case giant_spider:
        std::cout << "This Giant spider";
        break;
    case slime:
        std::cout << "This Slime";
        break;
    default:
        break;
    }
    std::cout << " is named " << monster.name;
    std::cout << " and has " << monster.damage << " health.\n";

}

int main()
{
    Monster m1{MonsterType::ogre, "Torg", 145};
    Monster m2{MonsterType::slime, "Blurp", 23};

    printMonster(m1);
    printMonster(m2);
}
