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
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> map{};
        unordered_map<int, int> map2{};
        for (int i = 0; i < s.length(); i++)
        {
            if(  map.find(s[i])!=map.end()   && map[s[i]]!=t[i]  || ( map2.find(t[i])!=map2.end() && map2[t[i]]!=s[i]))
            {

                return false;
            }
            else
            {
                map.insert({s[i], t[i]});
                map2.insert({t[i], s[i]});
            }
        }
        return true;
    }
};

int main()
{
    string s{"badc"};
    string t{"baba"};

    Solution ss;
    cout << ss.isIsomorphic(s, t) << '\n';
    return 0;
}
