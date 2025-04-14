#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>


std::mutex mtx;

int var = 0;

void t1()
{
    for (int i = 0; i < 100000;i++){


        std::unique_lock<std::mutex> locker(mtx);
        var++;


    }
}


void t2()
{
    for (int i = 0; i < 100000;i++){

        std::unique_lock<std::mutex> locker(mtx);
        var++;

    }
}


int main()
{
    std::thread tt1(t1);
    std::thread tt2(t2);

    tt1.join();
    tt2.join();

    std::cout << var << '\n';

    return 0;
}
