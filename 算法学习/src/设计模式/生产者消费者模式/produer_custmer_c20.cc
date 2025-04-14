#include<iostream>
#include<semaphore>
#include<thread>


const int buffer_size = 5;
std::binary_semaphore b_mutex(1);


std::counting_semaphore<buffer_size> b_full(0);
std::counting_semaphore<buffer_size> b_empty(5);


// class Producer
// {
// private:

//     std::binary_semaphore b_mutex(1);
//     std::counting_semaphore<buffer_size> b_full(0);
//     std::counting_semaphore<buffer_size> b_empty(5);

// public:
//     Producer(){}
//     ~Producer(){}
// };

void Producer(int id)
{
    while(true)
    {
        b_empty.acquire();
        b_mutex.acquire();

        std::cout << "Producer: " <<id<<"\n";

        b_mutex.release();
        b_full.release();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}


void Consumer(int id)
{
    while(true)
    {
        b_full.acquire();
        b_mutex.acquire();

        std::cout << "Consumer: "<<id<<"\n";

        b_mutex.release();
        b_empty.release();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}


int main()
{
    std::thread t0(Producer,0);
    std::thread t1(Consumer,0);

    std::thread t2(Producer,1);
    std::thread t3(Consumer,1);

    t0.join();
    t1.join();

    t2.join();
    t3.join();

    return 0;
}
