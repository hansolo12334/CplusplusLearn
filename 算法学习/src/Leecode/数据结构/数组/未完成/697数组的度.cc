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
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, pair<int, pair<int, int>>> map;
        for (int i = 0; i < nums.size(); i++)
        {

            if (map[nums[i]].first == 0)
            {
                map[nums[i]].second.first = i;
            }
            else
            {
                map[nums[i]].second.second = i;
            }
            map[nums[i]].first++;
        }
        int maxD = 1;
        // int num = -1;
        int minG = INT_MAX;
        for (auto iter = map.begin(); iter != map.end(); iter++)
        {
            if (iter->second.first > maxD)
            {
                maxD = iter->second.first;
                // num = iter->first;
                cout << iter->second.second.second << ' ' << iter->second.second.first << '\n';
                int g = iter->second.second.second - iter->second.second.first + 1;
                if(minG >g)
                {
                    minG = g;
                }
            }
        }

        return minG;
    }
};


int main()
{
    vector<int> nums{1,2,2,3,1,4,2};
    Solution s;
    cout << s.findShortestSubArray(nums) << '\n';
    return 0;
}
