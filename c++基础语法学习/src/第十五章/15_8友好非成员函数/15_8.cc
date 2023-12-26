#include<iostream>



//友元函数 可以访问类的私有变量和受保护成员 关键字: friend
class Accumulator
{
private:
    int m_value{};


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
};

void print(const Accumulator &acc)
{
    std::cout << acc.m_value << '\n';
    //友元函数 使得print能够访问Accumulator的私有变量
}

int main()
{
    Accumulator acc{};
    acc.add(5);
    print(acc);
    reduce(acc);
    print(acc);
    return 0;
}
