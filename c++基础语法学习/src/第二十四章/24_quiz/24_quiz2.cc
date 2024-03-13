#include<iostream>
#include<string>
#include<random>
#include<string_view>

class Creature
{
protected:
    std::string m_name{};
    char m_char{};
    int m_health{};
    int m_damage_pre_attack{};
    int m_gold_carring{};

public:
    Creature(std::string_view name,char chara,int health,int damege,int gold)
     : m_name{name}
     , m_char{chara}
     , m_health{health}
     , m_damage_pre_attack{damege}
     , m_gold_carring{gold}
     {

     }

     const std::string &getName()const{
         return m_name;
     }

     int getHealth() const
     {
         return m_health;
     }
     int getGold() const {
         return m_gold_carring;
     }
    char getSymbol() const{
        return m_char;
    }
    int getDamage() const
    {
        return m_damage_pre_attack;
    }

     void reduceHealth(int health)
     {
         m_health -= health;
     }
     bool isDead(){
        if(m_health<=0){
            return true;
        }
        return false;
     }
    void addGold(int gold){
        m_gold_carring += gold;
    }

};

class Player : public Creature
{
private:
    int m_level{1};

public:
    Player(std::string name)
     :Creature{name,'@',10,1,0}
    {

    }

    void levelUp()
    {
        m_level++;
        m_damage_pre_attack++;
    }

    int getLevel() const{
        return m_level;
    }

    bool isWon(){
        return m_level >= 20;
    }
};


class Monster : public Creature
{

public :

    enum Type {
    dragon,
    orc,
    slime,
    max_type
};


private :
     static inline Creature monsterData[]{
        Creature{"dragon",'D',20,4,100},
        Creature{"orc",'o',4,2,25},
        Creature{"slime",'s',1,1,10}
    };
    static_assert(std::size(monsterData) == max_type);

 public:
     Monster(Type t)
     : Creature{monsterData[t]}
    {

    }

    static Type getRandomMonster()
    {
        std::random_device rd{};
        std::mt19937 mt{rd()};
        std::uniform_int_distribution die6{0, 2};
        return static_cast<Type>(die6(mt));
    }
};



void attackPlayer(Player &p,Monster &m)
{
    p.reduceHealth(m.getDamage());
    std::cout << m.getName() << "hit you for " << m.getDamage() << " damage\n";
}
void attackMonster(Player &p,Monster &m)
{
    m.reduceHealth(p.getDamage());
    std::cout <<  "You hit " << m.getName() <<" for "<<p.getDamage()<< " damage\n";
    attackPlayer(p,m);
}


void getPotion(Player &p)
{
    std::random_device rd{};
    std::mt19937 mt{rd()};
    std::uniform_int_distribution die6{0, 10};
    if(die6(mt)>=3){
        return;
    }
    else
    {
        std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
        char choice{};
        std::cin >> choice;
        if (choice == 'y'){
            std::random_device rd{};
            std::mt19937 mt{rd()};
            std::uniform_int_distribution die6{0, 2};
            int posionIdx = die6(mt);
            if(posionIdx==0){
            // std::cout<<"You drink "
            }
        }
    }
}

void fightMonster(Player &p,Monster &m)
{
    while(true)
    {
        std::cout << "(R)un or (F)ight:";
        char dosome{};
        std::cin >> dosome;
        if(dosome=='R'){
            std::random_device rd{};
            std::mt19937 mt{rd()};
            std::uniform_int_distribution die6{0, 2};
            if(die6(mt)>=1){
                std::cout << "You successfully fled.\n";
                return;
            }
            else{
                std::cout << "You failed to flee.\n";
                attackPlayer(p,m);
            }

        }
        else if(dosome=='F'){
            attackMonster(p,m);
        }
        else{
            continue;
        }
        if(p.isDead()){
            std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold\n";
            std::cout << "Too bad you can’t take it with you!\n";
            return;
            getPotion(p);
        }
        if(m.isDead()){
            std::cout << "You killed the " << m.getName() << '\n';
            p.levelUp();
            p.addGold(m.getGold());
            std::cout << "You found " << p.getGold() << " gold.\n";
            return;
        }
        if(p.isWon()){
            std::cout << "You win!\n";
            return;
        }
    }

}


int main()
{
    std::string name{};
    std::cout << "Enter your name:";
    std::cin >> name;
    std::cout << "Welcome, " << name << '\n';

    Player p1{name};

    while(true)
    {
        Monster m{Monster::getRandomMonster()};
        std::cout << "You have encountered a " << m.getName() <<'('<<m.getSymbol()<< ").\n";
        fightMonster(p1,m);
        if(p1.isDead()){
            break;
        }
        if(p1.isWon()){
            break;
        }
    }

    return 0;
}
