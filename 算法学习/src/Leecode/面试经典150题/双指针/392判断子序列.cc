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
bool isSubsequence(string s, string t) {

}
};



int main()
{
    string s{"axc"};
    string t{"ahbgdc"};
    Solution ss;
    cout << ss.isSubsequence(s, t) << '\n';
    return 0;
}
