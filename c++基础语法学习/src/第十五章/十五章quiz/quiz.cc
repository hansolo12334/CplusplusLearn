#include<iostream>
#include<string>
#include<string_view>

#include"Random.h"

;

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };

    Monster(Type type,std::string name,std::string roar,int hit_points)
        : m_type{type}
        , m_name{name}
        , m_roar{roar}
        , m_hit_points{hit_points}
        {}

    void print() const{
        if(m_hit_points>0){
            std::cout << m_name << " the " << getTypeString() << " has " << m_hit_points << " hit points and says "
                  << m_roar << '\n';
        }
        else{
            std::cout << m_name << " the " << getTypeString() << " is dead\n";
        }
    }
    constexpr std::string_view getTypeString() const{
        switch (m_type)
        {
        case 0:
            return "dragon";
        case 1:
            return "goblin";
        case 2:
            return "ogre";
        case 3:
            return "orc";
        case 4:
            return "skeleton";
        case 5:
            return "troll";
        case 6:
            return "vampire";
        case 7:
            return "zombie";
        default:
            return "????";
        }
    }

private:

    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hit_points{};


};

namespace MonsterGenerator{



    constexpr std::string getName(int num){
        switch (num)
        {
            case 0:  return "Blarg";
            case 1:  return "Moog";
            case 2:  return "Pksh";
            case 3:  return "Tyrn";
            case 4:  return "Mort";
            case 5:  return "Hans";
            default: return "???";
        }
    }

    constexpr std::string getRoar(int num){
        switch (num)
        {
            case 0:  return "*ROAR*";
            case 1:  return "*peep*";
            case 2:  return "*squeal*";
            case 3:  return "*whine*";
            case 4:  return "*growl*";
            case 5:  return "*burp*";
            default: return "???";
        }
    }

    Monster generate(){
        return Monster{static_cast<Monster::Type>(Random::get(0, Monster::max_monster_types - 1)),
                       getName(Random::get(0, 5)),
                       getRoar(Random::get(0, 5)),
                       Random::get(1, 100)};
    }
}

int main()
{
	Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
	vampire.print();

    Monster m{ MonsterGenerator::generate() };
	m.print();
	return 0;
}
