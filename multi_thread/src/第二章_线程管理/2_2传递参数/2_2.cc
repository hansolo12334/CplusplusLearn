#include<iostream>
#include<thread>



void func(int i, const std::string & s)
{
    std::cout <<i <<" :"<< std::this_thread::get_id() << '\n';
    std::cout << s << '\n';
}

//传递参数
int main()
{
    std::string s{"hansolo"};
    std::thread t1(func, 1, s);
    t1.join();
    return 0;
}
