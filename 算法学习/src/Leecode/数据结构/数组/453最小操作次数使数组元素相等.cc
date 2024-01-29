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
    int minMoves(vector<int>& nums) {

        int n = nums.size();
        if(n==1 )
        {
            return 0;
        }
        sort(nums.begin(), nums.end());

        if(nums[0]==nums[n-1])
        {
            return 0;
        }
        int re = 0;
        for(int maxIndex = n - 1; maxIndex>0;maxIndex--)
        {
            re += nums[maxIndex] - nums[0];
        }
        return re;

    }

    //官方解法
    int minMoves1(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int re = 0;
        for(int num:nums)
        {
            re += num - minNum;
        }
        return re;
    }
};


int main()
{
    vector<int> nums{0,1};
    Solution s;
    cout << s.minMoves1(nums) << '\n';

    return 0;
}
