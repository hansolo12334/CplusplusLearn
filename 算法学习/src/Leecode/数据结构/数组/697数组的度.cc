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
        //                    first     .second.first  .second.second
        //                  出现次数  第一次出现位置 最后出现位置
        unordered_map<int, pair<int, pair<int, int>>> map;
        for (int i = 0; i < nums.size(); i++)
        {
            //如果第一次出现
            if (map[nums[i]].first == 0)
            {
                map[nums[i]].first = 1;
                map[nums[i]].second.first = i;
                map[nums[i]].second.second = i;
            }
            else
            {
                map[nums[i]].first++;
                map[nums[i]].second.second = i;
            }

        }
        int maxD = 0;
        // int num = -1;
        int minLen = 0;
        for (auto iter = map.begin(); iter != map.end(); iter++)
        {
            //计算出现次数最多的数字
            if (iter->second.first > maxD)
            {
                maxD = iter->second.first;
                minLen=iter->second.second.second - iter->second.second.first + 1;
            }
            else if(iter->second.first == maxD)
            {
                int g = iter->second.second.second - iter->second.second.first + 1;
                if(minLen >g)
                {
                    minLen = g;
                }
            }
        }
        return minLen;
    }

    //重写 不用std::pair
    int findShortestSubArray1(vector<int> &nums)
    {
        //                    first     .second.first  .second.second
        //                  出现次数  第一次出现位置 最后出现位置
        unordered_map<int, vector<int> > map;
        for (int i = 0; i < nums.size(); i++)
        {
            //如果第一次出现
            if (map.count(nums[i])==0)
            {
                map[nums[i]] = {1, i, i};
            }
            else
            {
                map[nums[i]][0]++;
                map[nums[i]][2] = i;
            }

        }
        int maxD = 0;
        // int num = -1;
        int minLen = 0;
        for (auto &[_,vec] : map)
        {
            //计算出现次数最多的数字
            if (vec[0] > maxD)
            {
                maxD = vec[0];
                minLen=vec[2] - vec[1] + 1;
            }
            else if(vec[0] == maxD)
            {
                int g = vec[2] - vec[1] + 1;
                if(minLen >g)
                {
                    minLen = g;
                }
            }
        }
        return minLen;
    }
};


int main()
{
    vector<int> nums{2,1};
    Solution s;
    cout << s.findShortestSubArray1(nums) << '\n';
    return 0;
}
