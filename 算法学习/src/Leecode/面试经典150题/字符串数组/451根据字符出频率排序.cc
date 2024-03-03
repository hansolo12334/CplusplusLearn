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
    string frequencySort(string s) {
        unordered_map<char, pair<int,string>> map;
        for (int i = 0; i < s.length();i++)
        {
            map[s[i]].first++;
            map[s[i]].second += s[i];
        }



        string re;
        while (map.size() != 0)
        {
            int max_size = INT_MIN;
            char character;
            for (auto p : map)
            {
                if(p.second.first>max_size)
                {
                    character = p.first;
                    max_size = p.second.first;
                }
            }
            re += map[character].second;
            map.erase(character);
        }
        return re;
    }
};



int main()
{
    string s{"tree"};
    Solution ss;
    cout << ss.frequencySort(s) << '\n';
    return 0;
}
