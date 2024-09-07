#include <iostream>
#include <thread>

// int mutex = 1;
// int full = 1;
// int empty = 1;


// struct A
// {
// public :
//  A(){}
//  ~A(){}
//  virtual void test(){
//      std::cout << 'A' << '\n';
//  }
// };

// struct B: public A
// {
// public:
//     B()
//      : c_int{2}
//     {}

//     ~B(){}

//     static int s_int;
//     const int c_int;

//     void test() override
//     {
//         std::cout << 'B' << '\n';
//     }
// };


// void productor()
// {

//     while(true){
//         if(empty){
//             empty = 0;
//             if(mutex){
//                 mutex = 0;
//                 std::cout << "productor\n";
//                 mutex = 1;
//             }
//             full = 1;
//         }
//         else{
//             continue;
//         }
//     }


// }

// void customer()
// {
//     while(true)
//     {
//         if(full){
//             full = 0;
//             if(mutex){
//                 mutex = 0;
//                 std::cout << "customer\n";
//                 mutex = 1;
//             }
//             empty = 1;
//         }
//         else{
//             continue;
//         }

//     }


// }

// int B::s_int = 1;


// void change(int *p)
// {
//     int a = 3;
//     p = &a;
// }
// int main()
// {
//     // std::thread t1(productor);
//     // std::thread t2(customer);


//     // t1.detach();
//     // t2.detach();

//     B b{};
//     b.test();
//     b.A::test();
//     std::cout << b.s_int << '\n';
//     std::cout << b.c_int << '\n';


//     int ss = 1;
//     int ss1 = 2;
//     int *ssp = &ss;
//     std::cout << ssp << ' ' << *ssp << '\n';
//     change(ssp);
//     std::cout << ssp << ' ' << *ssp << '\n';

//     return 0;
// }
// class Base
// {
// public:
//     Base()
//     {
//         std::cout << "Base\n";
//     }
// };

// class Derived : public Base
// {
// public:
//     Derived()
//     {
//         std::cout << "Derived\n";
//     }
// };

// class ContainsDerived
// {
//     Derived d;

// public:
//     ContainsDerived()
//     {
//         std::cout << "ContainsDerived\n";
//     }
// };

// class FurtherDerived : public ContainsDerived
// {
// public:
//     FurtherDerived()
//     {
//         std::cout << "FurtherDerived\n";
//     }
// };

// int main()
// {
//     FurtherDerived fd;
//     return 0;
// }
class B
{
public:
    B(){

    }

    virtual void out()
    {
        std::cout << "out  B\n";
    }
    virtual ~B()
    {
        std::cout << "delect B\n";
    }
};

class Test
{
public:
    Test()
    {
        std::cout << "默认Test "<< std::endl;
    }
    Test(int a)
    {
        std::cout << "int a " << a << std::endl;
    }
};
class B_1 : public B
{
public:
    B_1()
    : t1(1)
    {
        t2 = Test(2);
    }

    void out() override
    {
        std::cout << "out  B_1\n";
    }

    ~B_1()
    {
        std::cout << "delect B_1\n";
    }
    Test t1;
    Test t2;

    static void* operator new(size_t) = delete;
    static void operator delete(void *) = delete;
};

int main()
{
    B *b1=new B_1();
    b1->out();
    // b1->B::out();
    delete b1;

    int *a = new int[2];
    a[1] = 2;
    a[0] = 1;
    return 0;
}
