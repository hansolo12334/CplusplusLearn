#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;


class Solution
{
public:
    string reverseVowels(string s)
    {
        int j = s.size()-1;
        int i = 0;
        unordered_map<int, int> map{{'a', 1},
                                    {'e', 1},
                                    {'i', 1},
                                    {'o', 1},
                                    {'u', 1},
                                    {'A', 1},
                                    {'E', 1},
                                    {'I', 1},
                                    {'O', 1},
                                    {'U', 1}
                                    };

        while (i < j)
        {
            if(map.find(s[i])!=map.end() && map.find(s[j])!=map.end() )
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(map.find(s[i])==map.end())
            {
                i++;
            }
            else if(map.find(s[j])==map.end())
            {
                j--;
            }
            else if(map.find(s[i])==map.end() && map.find(s[j])==map.end())
            {
                i++;
                j--;
            }
        }
        return s;
    }
};


int main()
{
    string s{"leetcode"};
    Solution ss;
    cout << ss.reverseVowels(s) << '\n';
    return 0;
}
