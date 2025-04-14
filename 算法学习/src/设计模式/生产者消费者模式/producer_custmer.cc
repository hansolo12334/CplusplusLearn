#include<iostream>


#include<mutex>
#include<queue>
#include<thread>
#include<atomic>
#include<condition_variable>


class Producer
{
private:
    struct products_queue
    {
        std::mutex mtx;
        std::queue<int> products;
        std::condition_variable cond;
    } products_queue_;


    const int buffer_size_ = 25;

    std::atomic<bool> stop_signal_ = false;

    std::unique_ptr<std::thread> producer_thread_ = nullptr;


    void ProductionImpl()
    {
        int index = 0;
        while(!stop_signal_)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(15));

            std::unique_lock<std::mutex> lock(products_queue_.mtx);

            products_queue_.cond.wait(lock, [this] {
                return products_queue_.products.size() < buffer_size_ || stop_signal_;
            });



            products_queue_.products.push(index);

            std::cout << "producer push product: " << index << '\n';

            products_queue_.cond.notify_one();

            index++;
        }
    }

public:
    Producer(){}

    ~Producer(){}

    int Start()
    {
        producer_thread_ = std::make_unique<std::thread>(&Producer::ProductionImpl, this);

        return 0;
    }

    int GetProduct()
    {
        std::unique_lock<std::mutex> lock(products_queue_.mtx);



        std::cout << "products queue size: " << products_queue_.products.size() << '\n';

        products_queue_.cond.wait(lock, [this] {
            return !products_queue_.products.empty();
        });

        int product = products_queue_.products.front();

        products_queue_.products.pop();

        products_queue_.cond.notify_one();


        return product;
    }


    int Stop()
    {
        if(producer_thread_!=nullptr && producer_thread_->joinable())
        {
            stop_signal_ = true;

            producer_thread_->join();

            stop_signal_ = false;

            producer_thread_.reset(nullptr);
        }

        while(!products_queue_.products.empty())
        {
            products_queue_.products.pop();
        }

        return 0;
    }
};


int main()
{
    Producer producer;
    producer.Start();

    for (int i = 0; i < 30;i++)
    {
        int product = producer.GetProduct();

        std::cout << "consumer get product: " << product << '\n';

        std::this_thread::sleep_for(std::chrono::microseconds(30));
    }


    producer.Stop();

    return 0;
}
