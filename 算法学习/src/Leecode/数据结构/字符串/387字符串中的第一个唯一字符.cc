#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;

//ascii  a 97 - z 122


//哈希表
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size();i++)
        {

            map[s[i]]++;
        }
        for (int i = 0; i < s.size();i++)
        {
            if (map[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};


int main()
{
    string ss{"loveleetcode"};
    Solution s;
    std::cout << s.firstUniqChar(ss) << '\n';
    return 0;
}
