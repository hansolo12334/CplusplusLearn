#include<iostream>
#include<random>
#include<chrono>

//C++有一个包含各种时钟的计时库，我们可以用来生成种子值。
//为了尽量减少程序连续快速运行时两个时间值相同的几率，我们希望使用一些尽可能快地更改的时间度量。
//为此，我们将询问时钟从它可以测量的最早时间开始已经过去了多少时间。
//这个时间以“刻度”来衡量，这是一个非常小的时间单位（通常是纳秒，但也可能是毫秒）


//使用系统时钟进行种子设定
void set_seed_with_system_clock()
{
    std::mt19937 mt{
        static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())};

    std::uniform_int_distribution die6{1, 6};

    for (size_t i = 0; i < 40; i++)
    {
        std::cout << die6(mt) << '\t';
        if(i%10==0)
        {
            std::cout << '\n';
        }
    }
}


unsigned int getRandomDeviceValue()
{
    std::random_device rd{};
    return rd();
}
//使用随机设备进行种子设定
void set_seed_with_random_device()
{
    //std::mt19937 mt{std::random_device{}()};
    std::mt19937 mt{getRandomDeviceValue()};

    std::uniform_int_distribution die6{1, 6};
    for (size_t i = 0; i < 40; i++)
    {
        std::cout << die6(mt) << '\t';
        if (i%10==0)
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}


int main()
{

    set_seed_with_random_device();
    return 0;
}
