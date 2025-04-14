#include <iostream>
#include <mutex>
#include <thread>

#include <condition_variable>
#include <queue>


std::mutex mtx;

std::condition_variable cond;


std::queue<int> product_queue;

int buffer_size = 10;

void producer()
{
    int id = 0;
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::unique_lock<std::mutex> locker(mtx);

        cond.wait(locker, [&] { return product_queue.size() < buffer_size; });


        product_queue.push(id);
        std::cout << "生产者存入商品 " << id << '\n';

        cond.notify_one();
        id++;
        
    }
}


void producer1()
{
    int id = 0;
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::unique_lock<std::mutex> locker(mtx);

        if (cond.wait_for(locker, std::chrono::milliseconds(50), [&] { return product_queue.size() < buffer_size; }))
        {
            product_queue.push(id);
            std::cout << "生产者存入商品 " << id << '\n';

            cond.notify_one();
            id++;
        }
        else{
            std::cout << "buffer已满 等待取出\n";
        }
    }
}


int consumer_get()
{
    std::unique_lock<std::mutex> locker(mtx);

    cond.wait(locker, [&] { return !product_queue.empty(); });

    int product = product_queue.front();
    product_queue.pop();
    std::cout << "顾客取出商品\n";

    cond.notify_one();

    return product;
}


int consumer_get1()
{
    std::unique_lock<std::mutex> locker(mtx);


    if (cond.wait_for(locker, std::chrono::milliseconds(40), [&] { return !product_queue.empty(); }))
    {
        int product = product_queue.front();
        product_queue.pop();
        std::cout << "顾客取出商品\n";
        cond.notify_one();

        return product;
    }
    else
    {
        std::cout << "队列被生产者占用 跳过本次\n";
        return 0;
    }
}


int main()
{
    std::unique_ptr<std::thread> producer_t = std::make_unique<std::thread>(producer);

    for (int i = 0; i < buffer_size; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout << consumer_get() << '\n';
    }

    producer_t->join();
    producer_t.reset(nullptr);

    return 0;
}
