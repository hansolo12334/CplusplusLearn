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
//方法一 哈希表
    int majorityElement(vector<int>& nums) {
        int half = nums.size() / 2;
        int re{};
        unordered_map<long long, int> map{};
        for (int i = 0; i < nums.size();i++)
        {
            map[nums[i]]++;
        }
        for (int i = 0; i < nums.size();i++)
        {
            if(map[nums[i]]>half)
            {
                return nums[i];
            }
        }
        return 0;
    }
//方法二 排序 找中值
    int majorityElement1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


int main()
{
    vector<int> nums{3,2,3};
    Solution s;
    cout << s.majorityElement1(nums) << '\n';
    return 0;
}
