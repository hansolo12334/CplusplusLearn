#include<thread>
#include<iostream>

int mutex = 1;
int full = 1;
int empty = 1;


struct A
{
public :
 A(){}
 ~A(){}
 virtual void test(){
     std::cout << 'A' << '\n';
 }
};

struct B: public A
{
public:
    B()
     : c_int{2}
    {}

    ~B(){}

    static int s_int;
    const int c_int;

    void test() override
    {
        std::cout << 'B' << '\n';
    }
};


void productor()
{

    while(true){
        if(empty){
            empty = 0;
            if(mutex){
                mutex = 0;
                std::cout << "productor\n";
                mutex = 1;
            }
            full = 1;
        }
        else{
            continue;
        }
    }


}

void customer()
{
    while(true)
    {
        if(full){
            full = 0;
            if(mutex){
                mutex = 0;
                std::cout << "customer\n";
                mutex = 1;
            }
            empty = 1;
        }
        else{
            continue;
        }

    }


}

int B::s_int = 1;


void change(int *p)
{
    int a = 3;
    p = &a;
}
int main()
{
    // std::thread t1(productor);
    // std::thread t2(customer);


    // t1.detach();
    // t2.detach();

    B b{};
    b.test();
    b.A::test();
    std::cout << b.s_int << '\n';
    std::cout << b.c_int << '\n';


    int ss = 1;
    int ss1 = 2;
    int *ssp = &ss;
    std::cout << ssp << ' ' << *ssp << '\n';
    change(ssp);
    std::cout << ssp << ' ' << *ssp << '\n';

    return 0;
}
