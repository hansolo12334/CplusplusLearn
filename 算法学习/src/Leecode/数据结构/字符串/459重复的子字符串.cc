#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        for (size_t stringLen = 1; stringLen <= s.size() / 2;stringLen++)
        {
            if(s.size()%stringLen!=0)
            {
                continue;
            }
            size_t i{};
            bool temp{true};
            for (i = 0; i < stringLen; i++)
            //将字符串分成 s.size()/stringLen 块同时比较
            {
                for (size_t j = 1; j < s.size() / stringLen;j++)
                {
                    if (s[i] != s[i + j*stringLen])
                    {
                        temp = false;
                        break;
                    }
                }
            }
            if(!temp)
            {
                continue;
            }
            if(i>=stringLen)
            {
                return true;
            }
        }
        return false;
    }


//方法二 字符串匹配
    // abcabc
    // abcabc abcabc
    // 从 b 开始找abcabc 如果发现返回索引在复制的那串abcabc开头，
    // 则false,否则 返回索引一定在原来的字符串中。
    bool repeatedSubstringPattern1(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};


int main()
{
    string s{"abcabc"};
    Solution ss;
    cout << ss.repeatedSubstringPattern1(s) << '\n';
    return 0;
}
