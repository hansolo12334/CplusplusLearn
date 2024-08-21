#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>


class Solution
{
public:
    Solution(){}

    int findLongSubStr(std::string &str)
    {
        if(str.length()<=1){
            return str.length();
        }
        std::vector<int> map(26,0);
        for (int i = 0;i<map.size();i++)
        {
            map[i] = -1;
        }
        std::vector<int> dp(str.length(), 0);
        map[str[0]-'a']=0;
        dp[0] = 1;
        int maxLen = 1;
        for (int i = 1; i < str.length(); i++)
        {

            if(map[str[i]-'a']<0){
                map[str[i]-'a']=i;
                dp[i] = dp[i - 1] + 1;
            }
            else{
                dp[i] = std::min(dp[i - 1] + 1, i - map[str[i]-'a']);

                map[str[i]-'a']=i ;
            }
            maxLen = std::max(maxLen, dp[i]);
        }

        for(auto d:dp){
            std::cout << d << ' ';
        }
        std::cout << '\n';
        return maxLen;
    }
};

int main()
{
    std::string str{"bjvzbhvklndbyjqbfkeskqhegaeuovgvjijermcebtdhtmwuclvnklyetkfxvvglzjgafl"};

    Solution ss;

    std::cout << ss.findLongSubStr(str) << '\n';
    return 0;
}
