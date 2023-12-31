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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==1){
            return {strs};
        }
        unordered_map<string, vector<string>> mapp;
        vector<vector<string>> re{};
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mapp[temp].emplace_back(strs[i]);
        }
        for (auto iter = mapp.begin(); iter != mapp.end();iter++)
        {
            re.emplace_back(iter->second);
        }
        return re;
    }
};


int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sss;
    auto re = sss.groupAnagrams(strs);
    for(auto rr:re)
    {
        for(auto r:rr)
        {
            cout << r << ' ';
        }
        cout << '\n';
    }
    return 0;
}
