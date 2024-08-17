#include<iostream>

#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

#define ADD(x,y) x+y

class Base
{
public:
    Base()
    {
        func();
    }
    virtual ~Base()
    {
         func();
    }

    virtual void func()
    {
        cout << "base\n";
    }

    virtual void func1()
    {
        cout << "baseee\n";
    }
};


class Base1
{
public:
    Base1()
    {
        func();
    }
    virtual ~Base1()
    {
        func();
    }

    virtual void func()
    {
        cout << "base1\n";
    }
};

class partner1
{
public:
    partner1()
    {
        cout << "partner1\n";
    }
    ~partner1()
    {
        cout << "partner1\n";
    }
};

class partner2
{
public:
    partner2()
    {
        cout << "partner2\n";
    }
    ~partner2()
    {
        cout << "partner2\n";
    }
};

class Chunxu
{
public:
    Chunxu()
    {

    }
    virtual void func2() = 0;
};

class Child1 : public Base1, Base,Chunxu
{
public:
    Child1()
     : pt1{new partner1{}}
    {
        func();
    }
    ~Child1()
    {

        func();
        delete pt1;
    }

    virtual void func2()
    {

    }

    virtual void func()
    {
        cout << "Child\n";
    }

    partner1 *pt1 = nullptr;
    partner2 pt2;
};


int main()
{

    Child1 c1;

    auto pid=fork();

    // if(pid==0)
    // {
    //     execl("/home/hansolo/CplusplusLearn/算法学习/src/exec/build/test1","/home/hansolo/CplusplusLearn/算法学习/src/exec/build/test1", NULL);
    //     return 1;
    // }
    // else{
    //     wait(NULL);
    // }

    std::cout << ADD(1, 2)<<"xxxxxx " << '\n';


    int num = 1;
    cout << *(char *)&num << '\n';
    return 0;
}
