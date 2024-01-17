#include<thread>
#include<iostream>
#include<vector>
#include<chrono>
#include<future>


#include <atomic>





class test
{
private:
    int m_a;

    std::mutex mu;
    bool m_stopE = false;
    bool m_pause = false;
    std::condition_variable m_cv;

public:
    test(int a)
    : m_a{a}
    {}
    ~test();

    void update();
    void start();
    void end();
    void pause();
    void resume();

    // void operator()()
    // {
    //     start();
    // }
};
void test::start()
{
    std::thread t(&test::update,this);
    t.detach();
}

void test::update()
{
    while (true)
    {
        if(!m_stopE)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::unique_lock<std::mutex> lock(mu);
            m_cv.wait(lock, [this] { return !m_pause; });
        }
        if(m_stopE)
        {
            break;
        }
        std::cout << m_a << '\n';
    }
}
void test::end()
{
    std::cout<<"sssssssssssssss end \n";
    m_stopE = true;
}

void test::pause()
{
    std::unique_lock<std::mutex> lock(mu);
    m_pause = true;
    m_cv.notify_one();
}

void test::resume()
{
    std::unique_lock<std::mutex> lock(mu);
    m_pause = false;
    m_cv.notify_one();
}


test::~test()
{
}


void getIt(std::vector<test*> &tests)
{
    for (int i = 0; i < 3; i++)
    {
        // test my_test{i};
        test *my_test = new test(i);
        tests.push_back(my_test);
        // std::thread t1(*my_test);
        my_test->start();
        // t1.detach();

        // my_test->start();
    }
}


int main()
{
    std::vector<test *> tests;
    getIt(tests);


        for (int i = 0; i < 3;i++)
        {
            tests[i]->pause();
            std::cout << "--------------------\n";
        }

    while (1)
    {
        // std::cout << "run main\n";
    }
    return 0;
}
