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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> re;
        int i = 0;
        for (int j = 1; j <= n;)
        {
            while(i+1 <n && nums[i]==nums[i+1])
            {
                i++;
            }

            if(i<n&& j<nums[i])
            {
                while(j<nums[i])
                {
                    re.push_back(j);
                    j++;
                }
                j++;
            }
            else if( (i+1) <n&& j==nums[i])
            {
                i++;
                j++;
            }
            else if((i+1) <n && j>nums[i])
            {
                if(j<nums[i+1])
                {
                    while(j<nums[i+1])
                    {
                        re.push_back(j);
                        j++;
                    }
                    j++;
                }
                else{
                    i++;
                }
            }
            else if((i+1)>=n && j>nums[i])
            {
                while(j<=n)
                {
                    re.push_back(j);
                    j++;
                }
                j++;
            }
            else{
                j++;
            }
        }

        return re;
    }

//方法二 官方解法
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        int n=nums.size();
        for(auto &num:nums)
        {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> re;
        for (int i = 0; i < n;i++)
        {
            if(nums[i]<=n)
            {
                re.push_back(i + 1);
            }
        }
        return re;
    }
};



int main()
{
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> re = s.findDisappearedNumbers(nums);
    for(int r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
