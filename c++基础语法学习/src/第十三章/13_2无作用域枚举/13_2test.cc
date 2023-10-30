#include<iostream>
#include<string>
//定义一个名为 MonsterType 的枚举类型，以在以下怪物种族之间进行选择：兽人、妖精、巨魔、食人魔和骷髅。

//将 MonsterType 枚举放在命名空间中。然后，创建一个 main（） 函数并实例化一个巨魔。程序应该编译

namespace Monster
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };

} // namespace Monster


//打印枚举成员名称
//在 C++17 中，更有效的选项是替换 std::string 为 std::string_view
// std::string_view 允许我们以复制成本低得多的方式返回字符串文字
static constexpr std::string_view getSelectedMonsterName(Monster::MonsterType type)
{
    switch (type)
    {
    case 0:
        return "orc";
        break;
    case 1:
        return "goblin";
        break;
    case 2:
        return "troll";
        break;
    case 3:
        return "ogre";
        break;
    case 4:
        return "skeleton";
        break;
    default:
        return "None";
        break;
    }
}


int main()
{
    Monster::MonsterType monster{Monster::troll};


    std::cout << "选择怪物序号:\n 0.orc\n 1.goblin\n 2.troll\n 3.ogre\n 4.skeleton\n";
    int id{};
    std::cin >> id;
    Monster::MonsterType type{static_cast<Monster::MonsterType>(id)};

    std::cout << typeid(type).name() <<"   you get "<<getSelectedMonsterName(type)<< '\n';

    return 0;
}
