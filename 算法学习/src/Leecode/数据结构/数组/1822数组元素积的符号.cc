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
    int arraySign(vector<int>& nums) {
        int isZero{1};
        bool isNegative{false};
        for (size_t i = 0; i < nums.size();i++)
        {
            if(nums[i]==0)
            {
                return 0;
            }
            if(nums[i]<0)
            {
                isZero *= -1;
            }
        }
        return isZero;
    }
};



int main()
{
    vector<int> nums{-1,1,-1,1,-1};
    Solution s;
    cout << s.arraySign(nums) << '\n';
    return 0;
}
