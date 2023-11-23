#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //超时！！！！
    //     int re{0};
    //     for (size_t i = 0; i < prices.size()-1; i++)
    //     {
    //         for (size_t j = i+1; j < prices.size(); j++)
    //         {
    //             if( (prices[j]-prices[i]) >re)
    //             {
    //                 re = prices[j] - prices[i];
    //             }
    //         }
    //     }
    //     return re;
    // }

    int re{0};
    for (size_t i = 0; i < prices.size()-1; i++)
    {
        if( (prices[i+1]-prices[i])>=0)
        {
            re=prices[i+1]-prices[i]+re;
        }
    }
    return re;
    }
};


int main()
{
    std::vector<int> input{7, 1, 5, 3, 6, 4};

    Solution s;

    std::cout << s.maxProfit(input) << '\n';

    return 0;
}
