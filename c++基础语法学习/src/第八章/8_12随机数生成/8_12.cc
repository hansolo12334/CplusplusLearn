#include<iostream>

// 计算机通常无法生成真正的随机数（至少通过软件）。
// 相反，现代程序通常使用算法模拟随机性

//伪随机数生成器 （PRNG） Pseudo-random number generators


unsigned int LCG16() // our PRNG
{
    static unsigned int s_state{ 5323 };

    // Generate the next number

    // We modify the state using large constants and intentional overflow to make it hard
    // for someone to casually determine what the next number in the sequence will be.

    s_state = 8253729 * s_state + 2396403; // first we modify the state
    return s_state % 32768; // then we use the new state to generate the next number in the sequence
}

int main()
{
    // Print 100 random numbers
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << LCG16() << '\t';

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }

    return 0;

}
