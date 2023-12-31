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


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        //可能的思路 双指针 因为要求不重复
        //所以 只要知道 i j两端 数字就行 三个数之和为0 第三个数必然固定 只要i j不重复 第三个数必然不重复
        sort(nums.begin(), nums.end());
        vector<vector<int>> re{};

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int k = nums.size() - 1;
            for (int j = i + 1; j < nums.size() - 1;j++)
            {
                if(j>i+1 &&  nums[j]==nums[j-1]){
                    continue;
                }

                while(j<k && nums[i]+nums[j]+nums[k]>0) //先保证j始终在k的左侧 递减 直到三数之和不大于零
                {
                    k--;
                }
                if(j==k)
                {
                    break;
                }
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    re.push_back({nums[i], nums[j], nums[k]});
                }

            }

        }
        return re;


        return re;
    }
};


int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> re = s.threeSum(nums);
    for (auto rr : re)
    {
        for (int r : rr)
        {
            cout << r << ' ';
        }
        cout << '\n';
    }

    return 0;
}
