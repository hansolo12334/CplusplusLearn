#include<iostream>


//Q4 编写一个简短的程序来模拟从塔上掉下来的球。首先，应询问用户塔的高度（以米为单位）。
//假设正常重力（9.8米/秒 2 ），并且球没有初始速度（球没有移动开始）。
//让程序在 0、1、2、3、4 和 5 秒后输出球离地面的高度。球不应进入地面下方（高度 0）。

//使用函数计算 x 秒后球的高度。该函数可以使用以下公式计算球在 x 秒后落下的距离：
//落下距离 = gravity_constant * x_seconds 2 / 2



double cal_ball_height(int x_second, double tower_height)
{
    constexpr double gravity_constant{9.8};
    return tower_height-gravity_constant *x_second*x_second/ 2;
}
int main()
{

    double tower_height{};
    std::cout << "Enter the height of the tower in meters:";
    std::cin >> tower_height;
    int fall_time{5};
    for (size_t i = 0; i <= fall_time; i++)
    {
        double ball_height{cal_ball_height(i, tower_height)};
        if (ball_height <= 0)
        {
            std::cout << "At " << i << " seconds, the ball is on the ground\n";
            break;
        }
        else{
            std::cout << "At " << i << " seconds, the ball is at height: " << ball_height << " meters\n";
        }

    }
    return 0;
}
