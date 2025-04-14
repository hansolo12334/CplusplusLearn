#include<iostream>
#include<string>
#include<list>


class Subject;


class Observer
{
protected:
    std::string name;
    Subject *sub;


public:
    Observer(std::string name, Subject *sub)
    {
        this->name = name;
        this->sub = sub;
    }

    virtual void update() = 0;
};

class StockObserver: public Observer
{
public:
    StockObserver(std::string name,Subject *sub)
     : Observer(name,sub)
     {

     }

     void update();
};


class NBAObserver: public Observer
{
public:
    NBAObserver(std::string name,Subject *sub)
     : Observer(name,sub)
    {

    }

    void update() override;
};


class Subject
{
protected:
    std::list<Observer *> observers;

public:
    std::string action; //被观察者对象的状态

    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;

    virtual void notify() = 0;
};


class Secretary: public Subject
{

public:

    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }

    void detach(Observer *observer)
    {
        std::list<Observer *>::iterator iter = observers.begin();

        while(iter!=observers.end())
        {
            if((*iter)==observer)
            {
                observers.erase(iter);
                return;
            }
            ++iter;
        }
    }

    void notify() override
    {
        std::list<Observer *>::iterator iter = observers.begin();

        while(iter!=observers.end())
        {
            (*iter)->update();
            ++iter;
        }
    }
};


void StockObserver::update()
{
    std::cout << name << " 收到消息: " << sub->action << '\n';
    if(sub->action=="老板来了!")
    {
        std::cout << "我马上关闭股票，装作认真工作的样子！ \n";
    }
}


void NBAObserver::update()
{
    std::cout << name << " 收到消息: " << sub->action << '\n';
    if(sub->action=="老板来了!")
    {
        std::cout << "我马上关闭NBA，装作认真工作的样子！ \n";
    }
}


int main()
{
    Subject *BOSS = new Secretary();

    Observer *xa = new NBAObserver("xa", BOSS);
    Observer *xb = new NBAObserver("xb", BOSS);
    Observer *xc = new NBAObserver("xc", BOSS);


    BOSS->attach(xa);
    BOSS->attach(xb);
    BOSS->attach(xc);

    BOSS->action = "吃饭";
    BOSS->notify();

    std::cout << std::endl;


    BOSS->action = "老板来了!";
    BOSS->notify();

    return 0;
}
