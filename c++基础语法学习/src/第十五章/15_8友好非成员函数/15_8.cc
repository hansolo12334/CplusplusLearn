#include<iostream>

//多个朋友 需要在此前向声明Foo
class Foo;

//友元函数 可以访问类的私有变量和受保护成员 关键字: friend
class Accumulator
{
private:
    int m_value{1};


public:
    void add(int value){
        m_value += value;
    }


    //friend 声明 使得非成员函数 void print 成了 Accumulator的friend

    friend void print(const Accumulator &acc);

    //或者直接定义在内部 但是它是非成员函数！
    friend void reduce(Accumulator &acc){
        acc.m_value--;
    }

    //多个朋友
    friend void printAccumulatorAndFoo(const Accumulator &acc,const Foo &fo);
};

void print(const Accumulator &acc)
{
    std::cout << acc.m_value << '\n';
    //友元函数 使得print能够访问Accumulator的私有变量
}


//多个朋友
class Foo
{
private:
    int m_value{2};

public:
    friend void printAccumulatorAndFoo(const Accumulator &acc,const Foo &fo);
};


void printAccumulatorAndFoo(const Accumulator &acc,const Foo &fo){
    std::cout << "Accumulator is "<< acc.m_value << "   Foo is "<< fo.m_value << '\n';
}
//  友元函数应尽可能使用类接口而不是直接访问
int main()
{
    Accumulator acc{};
    acc.add(5);
    print(acc);
    reduce(acc);
    print(acc);

    Foo fo{};
    printAccumulatorAndFoo(acc,fo);
    return 0;
}
