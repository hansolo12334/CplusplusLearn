#include<iostream>
#include<string_view>
#include<string>



class Base
{
public:
    virtual void print(){
        std::cout << "Base\n";
    }

public:
    Base(){
        print();
    }
    ~Base(){
         std::cout << "Base ~\n";
    }
};

class Derived: public Base
{
public:
    void print(){
        std::cout << "Derived\n";
    }
    Derived(){
         print();
    }
    ~Derived(){
        print();
        std::cout << "~\n";
    }
};

int main()
{
    Derived b{};
}
