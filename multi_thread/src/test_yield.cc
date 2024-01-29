#include <coroutine>
#include <deque>
#include <functional>
#include <iostream>
#include <thread>
#include <atomic>


using taskFuc = std::function<void(int)>;

class TaskScheduler
{
private:
    std::deque<std::pair<taskFuc,int>> task_que{};

public:
    TaskScheduler()
    {}

    void add_task(taskFuc func,int input){
        task_que.push_back({func,input});
    }

    void run()
    {
        while(!task_que.empty())
        {
            auto task = task_que.front();
            task_que.pop_front();

            try
            {
                task.first(task.second);
                task_que.push_back(task);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

        }
    }
};


void loop1(int input)
{

    while (input)
    {
        std::cout << input << '\n';
        std::this_thread::yield();
        input--;
    }
}

void loop2(int input)
{

    while (input)
    {
        std::cout << input << '\n';

        input--;
    }
}

int main()
{
    TaskScheduler my_tasks{};
    my_tasks.add_task(loop1,4);
    my_tasks.add_task(loop2,6);
    my_tasks.run();
    return 0;
}
