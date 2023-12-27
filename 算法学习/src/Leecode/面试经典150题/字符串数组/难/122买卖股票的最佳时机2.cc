#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>

using namespace std;


class Solution {
public:
//方法一 贪心算法
    int maxProfit(vector<int>& prices) {
        //走低趋势不买 走高趋势买入
        int re{};
        for (int i = 0; i < prices.size()-1;i++)
        {
            if(prices[i+1]-prices[i]>0)
            {
                re = re + (prices[i + 1] - prices[i]);
            }
        }
        return re;
    }

//方法二 动态规划
/*
dp[i][j] 表示第i天 持股状态为i时 手上拥有的最大现金数额
j=0: 持有现金 没有股票
j=1: 持有股票

即 每天有两种状态
1.不买这天的股票 存着之前赚到的钱
2.买下这天的股票 消耗点赚到的钱

*/
int maxProfit1(vector<int>& prices) {
    int len = prices.size();
    if(len<2)
    {
        return 0;
    }
    vector<vector<int>> dp(len, vector<int>(2));

    //初始化第一天的状态
    //第一天 肯定没赚到钱
    dp[0][0] = 0;
    //第一天 买下这天的股票  花出去prices[0]，即赚到 -prices[0]
    dp[0][1] = -prices[0];

    for (int i = 1; i < len;i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); //状态转移方程
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); //状态转移方程
    }
    return dp[len - 1][0];
}
};



int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution s;
    cout << s.maxProfit1(prices) << '\n';
    return 0;
}
