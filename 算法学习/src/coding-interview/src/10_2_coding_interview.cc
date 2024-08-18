#include<iostream>
#include<algorithm>
#include<vector>



class Solution
{
public:
    Solution(){}

    int jumpStage(int n)
    {
        if(n<3)
        {
            return n;
        }
        int a = 1, b = 2;
        for (int i = 3; i <=n;i++){
            b = a + b;
            a = b - a;
        }
        return b;
    }
};


int main()
{
    int n = 5;
    Solution ss;
    std::cout << ss.jumpStage(n) << '\n';

    return 0;
}
