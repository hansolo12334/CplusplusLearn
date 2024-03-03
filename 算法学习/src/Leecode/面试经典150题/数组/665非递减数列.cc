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
    bool checkPossibility1(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1;i++)
        {
            int x = nums[i];
            int y = nums[i + 1];
            if(x>y)//若出现左边比右边大 只判断一次就退出
            {
                nums[i] = y;
                if(is_sorted(nums.begin(),nums.end()))
                {
                    return true;
                }
                nums[i] = x;
                nums[i + 1] = x;
                return is_sorted(nums.begin(), nums.end());
            }
        }
        return true;
    }

    //优化
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x = nums[i];
            int y = nums[i + 1];
            if(x>y)
            {
                cnt++;
                if(cnt>1)
                {
                    return false;
                }
                if(i>0&& y<nums[i-1])
                {
                    nums[i + 1] = x;
                }
            }
        }
        return true;
    }
};



int main()
{
    vector<int> nums{-1,4,2,3};
    Solution s;
    cout << s.checkPossibility(nums) << '\n';
    return 0;
}
