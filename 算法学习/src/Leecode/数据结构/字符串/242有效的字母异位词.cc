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

    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        vector<int> map(26, 0);
        for (size_t i = 0; i < s.size(); i++)
        {
            map[static_cast<int>(s[i])-97]++;
        }

        for (size_t i = 0; i < t.size(); i++)
        {
            --map[static_cast<int>(t[i])-97];
        }
        for (size_t i = 0; i < map.size();i++)
        {
            if (map[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    //方法二 哈希表
    bool isAnagram1(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char, int> map{};
        for (size_t i = 0; i < s.size(); i++)
        {
            map[s[i]-'a']++;
            map[t[i]-'a']--;
        }
        for (size_t i = 0; i < map.size();i++)
        {
            if(map[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};



int main()
{
    string s{"a"};
    string t{"ab"};

    Solution ss;

    cout << ss.isAnagram1(s, t) << '\n';
    return 0;
}
