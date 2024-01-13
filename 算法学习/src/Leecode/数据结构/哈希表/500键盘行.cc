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
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> map1{
            {'q',1},
            {'w',1},
            {'e',1},
            {'r',1},
            {'t',1},
            {'y',1},
            {'u',1},
            {'i',1},
            {'o',1},
            {'p',1}
        };
        unordered_map<char,int> map2{
            {'a',1},
            {'s',1},
            {'d',1},
            {'f',1},
            {'g',1},
            {'h',1},
            {'j',1},
            {'k',1},
            {'l',1}
        };
        unordered_map<char,int> map3{
            {'z',1},
            {'x',1},
            {'c',1},
            {'v',1},
            {'b',1},
            {'n',1},
            {'m',1}
        };

        vector<string> re;
        for (int i = 0; i < words.size(); i++)
        {
            int mapChoise = 0;
            char c = tolower(words[i][0]);
            if (map1.find(c) != map1.end())
            {
                mapChoise = 1;
            }
            else if(map2.find(c) != map2.end())
            {
                mapChoise=2;
            }
            else
            {
                mapChoise = 3;
            }
            int count = words[i].length();
            for (int j = 1; j < words[i].length(); j++)
            {
                c = tolower(words[i][j]);
                if (mapChoise == 1)
                {
                    if(map1.find(c)!=map1.end())
                    {
                        count--;
                    }
                    else
                    {
                        break;
                    }
                }
                if (mapChoise == 2)
                {
                    if(map2.find(c)!=map2.end())
                    {
                        count--;
                    }
                    else
                    {
                        break;
                    }
                }
                if (mapChoise == 3)
                {
                    if(map3.find(c)!=map3.end())
                    {
                        count--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(count==1)
            {
                re.push_back(words[i]);
            }
        }
        return re;
    }
};



int main()
{
    vector<string> words{"Hello", "Alaska", "Dad", "Peace"};
    Solution s;
    vector<string> re = s.findWords(words);
    for(auto r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
