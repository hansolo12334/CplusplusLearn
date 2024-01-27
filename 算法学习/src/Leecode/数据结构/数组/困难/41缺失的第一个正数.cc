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
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for (int i = 0; i < n;i++)
        {
            if(nums[i]!=i+1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};



int main()
{
    vector<int> nums{3, 4, -1, 1};
    Solution s;
    cout << s.firstMissingPositive(nums) << '\n';

    return 0;
}
