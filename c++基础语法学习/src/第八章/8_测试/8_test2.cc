#include<iostream>
#include"Random.h"

//Q1: 实施一个hi-lo游戏。首先，程序应选取一个介于 1 和 100 之间的随机整数。用户有 7 次尝试猜测数字。

/*
如果用户没有猜到正确的数字，程序应该告诉他们猜得太高还是太低。
如果用户猜到了正确的数字，程序应该告诉他们他们赢了。
如果他们没有猜测，程序应该告诉他们他们输了，以及正确的数字是多少。
在游戏结束时，应该询问用户是否要再次玩。
如果用户未输入“y”或“n”，请再次询问他们。
*/


/*
Q2:更新以前的解决方案以处理无效猜测（例如“x”）、越界猜测（例如 0 or 101 ）或包含无关字符的有效猜测（例如 43x ）。还要处理用户在游戏询问他们是否要再次玩游戏时输入额外角色的问题。
*/

int getAndCheckUserInput(int round)
{
    int guessNumber{0};
    while (true)
    {
        std::cout << "Guess #" << round << ':';
        std::cin >> guessNumber;

        if (std::cin.fail())//如果输入的变量类型不是定义的 int类型 就发生错误
        {
            std::cout << "输入不规范!\n";
            std::cin.clear();
            //把标准输入缓冲区cin的所有数据都清空
            //std::numeric_limits<std::streamsize>::max() 相当于IO流的最大字符个数
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            //std::cout << std::numeric_limits<std::streamsize>::max() << '\n';
            //9223372036854775807

            continue;
        }

        if(guessNumber>100 or guessNumber<1)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return guessNumber;
    }
}


void gameLoop()
{

    std::cout<< "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    int number{Random::get(1, 100)};
    int round{0};
    while(true)
    {
        if(round > 7)
        {
            std::cout << "Sorry, you lose. The correct number was " << number << ".\n";
            break;
        }


        int guessNumber{getAndCheckUserInput(round)};

        if (guessNumber>number)
        {
            std::cout << "Your guess is too high.\n";
        }
        else if (guessNumber<number)
        {
            std::cout << "Your guess is too low.\n";
        }
        else
        {
            std::cout << "Correct! You win!\n";
            break;
        }
        round++;
    }
}





bool confirmQuit()
{
    while (true)
    {
        std::cout << "Would you like to play again (y/n)?";
        char judge{};
        std::cin >> judge;



        if (judge == 'y')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }
        else if (judge=='n')
        {
            std::cout << "Thank you for playing.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }


}

int main()
{
    do
    {
        gameLoop();
    } while (confirmQuit());

    return 0;
}
