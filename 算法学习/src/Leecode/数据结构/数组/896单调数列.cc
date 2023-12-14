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
    bool isMonotonic(vector<int>& nums) {
        int dandiao{0};
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if((nums[i+1]-nums[i])!=0 && dandiao==0)
            {
                dandiao= (nums[i+1] - nums[i]) > 0 ? 1 : -1;
                continue;
            }
            if( (nums[i+1]-nums[i])!=0 && ((nums[i+1]-nums[i])>0? 1 :-1)!=dandiao)
            {
                return 0;
            }

        }
        return 1;
    }
};


int main()
{
    vector<int> nums{-5,-5,-5,-5,-2,-2,-2,-1,-1,-1,0};
    Solution ss;
    cout << ss.isMonotonic(nums) << '\n';
    return 0;
}
