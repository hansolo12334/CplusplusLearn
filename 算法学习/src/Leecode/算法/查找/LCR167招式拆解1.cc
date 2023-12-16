#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

#include <deque>
#include <queue>


using namespace std;


class Solution {
public:
    int dismantlingAction(string arr) {
        if(arr.size()==1)
        {
            return 1;
        }
        if(arr.size()==0)
        {
            return 0;
        }

        unordered_map<char,int> map{};

        int re{};
        for (int i = 0; i < arr.size()-1; i++)
        {
            int temp{};
            map[arr[i]] = i + 1;
            temp++;
            for (int j = i + 1; j < arr.size(); j++)
            {
                //cout << "map[arr[j]]= " << map[arr[j]] << '\n';
                if (map[arr[j]]!=0)
                {
                    re = re > temp ? re : temp;
                    i = map[arr[j]]-1;
                    map.clear();
                    cout << "i= " << i << '\n';
                    if(j+1==arr.size())
                    {
                        return re;
                    }
                    break;
                }
                map[arr[j]] = j + 1;
                temp++;
                re = re > temp ? re : temp;
                if(j+1==arr.size())
                {
                    return re;
                }
            }
        }
        return re;
    }
};


int main()
{
    string arr{"dbascDdad"};
    Solution ss;
    cout << ss.dismantlingAction(arr) << '\n';
    return 0;
}
