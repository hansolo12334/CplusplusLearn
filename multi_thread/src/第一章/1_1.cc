#include <iostream>
#include <memory>
#include <thread>


void printHello()
{
    std::cout << std::this_thread::get_id() << ' ';
    std::cout << "hello hansolo\n";
}

int main()
{
    std::thread t1{printHello};
    t1.join();

    std::thread t2{[]() {
        std::cout << std::this_thread::get_id() << ' ';
        std::cout << "hello world\n"; }};

    t2.join();//让主线程等待 std::thread对象创建的线程

    return 0;
}
