#include<iostream>
#include<algorithm>
#include<vector>



class Solution
{
public:
    Solution(){}

    int fibbo(int n)
    {
        if(n<2)
        {
            return n;
        }

        int a = 1, b = 1;
        for (int i = 2; i < n;i++)
        {
            b = a + b;
            a = b - a;
        }
        return b;
    }
};
//斐波那契

int main()
{
    int n = 5;
    Solution ss;
    std::cout << ss.fibbo(5) << '\n';
    return 0;
}
