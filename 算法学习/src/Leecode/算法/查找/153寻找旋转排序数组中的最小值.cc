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
//二分法 查找
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left<right)
        {
            int mid = (left + right) / 2;
            if(nums[mid]<nums[right])
            {
                right = mid;
            }
            else if(nums[mid]>nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right--;
            }
        }
        return nums[left];
    }
};

int main()
{
    vector<int> nums{2,1};
    Solution ss;
    cout << ss.findMin(nums) << '\n';
    return 0;
}
