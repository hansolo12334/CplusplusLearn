#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;


class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i<j)
        {
            //如果 相同 则继续
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
            // 如果不相同 则 考虑 i+1 和 j-1 左右 跳过一个字符的情况 如果这两个字串有一个是回文串 则返回 true 否则就没有再比较下去的必要了
                return checkRestList(i+1, j, s) || checkRestList(i, j-1, s);
            }
        }
        return true;
    }
    bool checkRestList(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};


int main()
{
    string s{"aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"};
    Solution ss;
    cout << ss.validPalindrome(s) << '\n';
    return 0;
}
