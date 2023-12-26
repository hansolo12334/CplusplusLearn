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
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        int i = 0;
        for (; i < nums.size()-1; i++)
        {

            while (j<nums.size() && nums[i]==nums[j])
            {
                j++;
            }
            if(j>=nums.size())
            {
                break;
            }
            nums[i + 1] = nums[j];
        }
        return i+1;
    }
};


int main()
{
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    Solution s;
    cout << s.removeDuplicates(nums) << '\n';

    for(int n: nums)
    {
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}
