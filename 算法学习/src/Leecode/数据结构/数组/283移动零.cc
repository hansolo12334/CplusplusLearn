#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (size_t i = 0; i < nums.size();i++)
        {
            if(nums[i]==0)
            {
                for (size_t j = i + 1; j < nums.size(); j++)
                {
                    if(nums[j] != 0)
                    {
                        swap(nums[j],nums[i]);
                        break;
                    }
                }
            }
        }
    }

    void moveZeroes1(vector<int>& nums) {
        size_t j{0};
        for (size_t i = 0; i < nums.size();i++)
        {
            if (nums[i] != 0)
            {
                int temp{nums[i]};
                nums[i] = nums[j];
                nums[j] = temp;
                j++;

            }
        }
    }
};



int main()
{
    vector<int> nums{0, 1, 0, 3, 12};
    Solution ss;
    ss.moveZeroes1(nums);
    for(int r:nums)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
