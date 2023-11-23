#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum{0};


        for (int num: nums)
        {
            sum += num;

        }

        if((sum-nums[0])==0 )
        {
            return 0;
        }

        int temp{nums[0]};
        for (size_t i = 0; i < nums.size()-1; i++)
        {
            if ( (sum-temp)==(temp+nums[i+1]) )
            {

                return i + 1;
            }
            temp += nums[i+1];
        }
        return -1;
    }
};

int main()
{
    std::vector<int> nums{1,7,3,6,5,6};
    Solution s;

    int re{s.pivotIndex(nums)};
    std::cout << re << '\n';
    return 0;
}
