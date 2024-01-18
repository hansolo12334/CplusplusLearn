#include<iostream>
#include<chrono>



class Timer
{
private:
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;
    std::chrono::time_point<Clock> m_beg{Clock::now()};


public:

    void reset()
    {
        m_beg = Clock::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};


int main()
{
    Timer t;

    for (int i = 0; i < 10000;i++)
    {
        for (int j = 0; j < 1000;j++)
        {

        }
    }

    std::cout << "Using time: " << t.elapsed() << '\n';
    return 0;
}
