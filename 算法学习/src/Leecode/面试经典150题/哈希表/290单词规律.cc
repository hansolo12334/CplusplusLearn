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
    bool wordPattern(string pattern, string s) {
        unordered_map<int, string> map1;
        unordered_map<string, int> map2;
        int j = 0;
        for (int i = 0; i < pattern.size(); i++)
        {
            //找到单词
            string in{};
            while (j<s.size() && s[j] != ' ')
            {
                in.push_back(s[j]);
                j++;
            }
            j++;

            if((i+1<pattern.size()&&j>=s.size()) || map1.count(pattern[i]) &&map1[pattern[i]]!=in || map2.count(in)&& map2[in]!=pattern[i] )
            {
                return false;
            }
            map1[pattern[i]] = in;
            map2[in] = pattern[i];
        }


        return j<s.size()? false:true;
    }
};



int main()
{

    string pattern{"abba"};
    string s{"dog cat cat dog"};
    Solution ss;
    cout << ss.wordPattern(pattern, s) << '\n';
    return 0;
}
