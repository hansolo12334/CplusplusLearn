#include<iostream>
#include<algorithm>
#include<vector>



class Solution
{
public:
    Solution(){}

    int maxSumVec(std::vector<int> &input)
    {
        if(input.size()<1)
        {
            return input[0];
        }
        std::vector<int> dp(input.size());
        int sum = input[0];
        dp[0] = sum;
        for (int i = 1; i < input.size(); i++)
        {
            dp[i] = std::max(dp[i - 1] + input[i], input[i]);
            sum = std::max(dp[i], sum);
        }
        for(auto r:dp)
        {
            std::cout << r << ' ';
        }
        return sum;
    }
};


//连续子数组的最大和
int main()
{
    std::vector<int> input{1, -2, 3, 10, -4, 7, 2, -5};

    Solution ss;
    std::cout << ss.maxSumVec(input) << '\n';
    return 0;
}
