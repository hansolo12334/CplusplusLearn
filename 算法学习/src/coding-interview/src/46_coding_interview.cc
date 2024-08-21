#include<iostream>
#include<algorithm>
#include<vector>



class Solution
{
public:
    Solution(){}

    int trans2str(std::string &str){
        std::vector<int> dp(str.length(),0);

        dp[0] = 1;
        dp[1] = str[0] == '1' ? 2 : 1;
        for (int i = 2; i < str.length(); i++)
        {
            dp[i] = dp[i - 1];
            if (str[i-1] == '1' || (str[i-1] == '2' && str[i] <= '5'))
            {
                dp[i] = dp[i - 2] + dp[i - 1];
            }
        }

        return dp[str.length() - 1];
    }
};


int main()
{
    std::string str{"12258"};

    Solution ss;
    std::cout << ss.trans2str(str) << '\n';
    return 0;
}
