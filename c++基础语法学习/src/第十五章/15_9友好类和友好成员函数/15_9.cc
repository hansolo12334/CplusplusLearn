#include<iostream>

class Storage
{
private:
    int m_nValue{};
    double m_dValue{};

public:
    Storage(int nValue,double dValue)
        : m_nValue{nValue}
        , m_dValue{dValue}
        {}

    friend class Display;
    //因为在此声明了Display是Storage的友元类 所以Display的成员有权访问Storage的私有变量
};

class Display
{
private:
    bool m_displyInit{};

public:
    Display(bool displayInit)
        : m_displyInit{displayInit}
        {}

    void displaStoraget(const Storage &storage)
    {
        if(m_displyInit){
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        }
        else{
            std::cout << storage.m_dValue << ' ' << storage.m_nValue <<'\n';
        }
    }

    void setDisplayIntFirst(bool b){
        m_displyInit = b;
    }
};
//class的 友谊不能传递 比如 如果class A是B的朋友，B是C的朋友，但A不是C的朋友
int main()
{
    Storage storage{5, 6.7};
    Display display{false};

    display.displaStoraget(storage);

    display.setDisplayIntFirst(true);

    display.displaStoraget(storage);

    return 0;
}
