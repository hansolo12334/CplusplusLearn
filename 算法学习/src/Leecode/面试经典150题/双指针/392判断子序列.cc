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

//方法一 双指针
    bool isSubsequence(string s, string t) {
        int len_s = s.length()-1;
        int len_t = t.length()-1;
        if(len_s>len_t)
        {
            return false;
        }
        while(len_s>=0)
        {
            if(s[len_s]==t[len_t])
            {
                len_s--;
                len_t--;
            }
            else
            {
                len_t--;
                if(len_t<0)
                {
                    return false;
                }
            }

        }
        return true;
    }

//方法二 动态规划
bool isSubsequence1(string s, string t) {
    //先预处理 t
    int n = s.size();
    int m = t.size();
    //初始化dp矩阵
    vector<vector<int>> dp(m+1, vector<int>(26, 0));
    for (int i= 0; i < 26;i++)
    {
        dp[m][i] = m;
        cout << dp[m][i] << ' ';
    }
    cout << '\n';
    //根据 t 构建 dp矩阵
    for (int i = m - 1; i >= 0;i--){
        for (int j = 0; j < 26;j++)
        {
            if(t[i]==j+'a')
            {
                dp[i][j] = i;
            }
            else
            {
                dp[i][j] = dp[i + 1][j];
            }
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    int add = 0;
    // 这步才 引入 s 来判断
    for (int i = 0; i < n;i++)
    {
        if(dp[add][s[i]-'a']==m)
        {
            return false;
        }
        add = dp[add][s[i] - 'a'] + 1;
    }
    return true;
    }
};



int main()
{
    string s{"abc"};
    string t{"ahbgdc"};
    Solution ss;
    cout << ss.isSubsequence1(s, t) << '\n';
    return 0;
}
