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
    string mergeAlternately(string word1, string word2) {
        size_t sp{0};
        size_t sp1{0};
        string re{};
        while (sp < word1.size() && sp1 < word2.size())
        {
            re += word1[sp];
            re += word2[sp1];
            sp++;
            sp1++;
        }
        if(sp<word1.size())
        {
            while(sp < word1.size())
            {
                re+=word1[sp];
                sp++;
            }
        }
        if(sp1<word2.size())
        {
            while(sp1 < word2.size())
            {
                re+=word2[sp1];
                sp1++;
            }
        }
        return re;
    }
    //方法二
    string mergeAlternately1(string word1, string word2) {
        string re;
        size_t sp1{0};
        size_t sp2{0};
        while( sp1<word1.size()|| sp2<word2.size())
        {
            if(sp1<word1.size())
            {
                re += word1[sp1];
                sp1++;
            }
            if(sp2<word2.size())
            {
                re += word2[sp2];
                sp2++;
            }
        }
        return re;
    }
};


int main()
{
    string word1{"ab"};
    string word2{"pqrs"};
    Solution s;
    cout << s.mergeAlternately1(word1, word2)<<'\n';
    return 0;
}
