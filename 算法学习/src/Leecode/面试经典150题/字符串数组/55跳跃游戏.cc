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
    bool canJump(vector<int>& nums) {
        int maxSize = nums.size();
        if(maxSize==1&& nums[0]>=0){
            return true;
        }
        vector<vector<int>> dp(maxSize, vector<int>(2, -1));
        vector<int> endList{};
        for (int i = 0; i < maxSize; i++)
        {
            int f = 1;
            dp[i][0] = f + i;
            dp[i][1] = f + nums[i] + i-1;
            if(dp[i][0]<=(maxSize-1) && dp[i][1]>=(maxSize-1)){
                endList.push_back(i);
            }
        }
        if(endList.empty()){
            return false;
        }
        int first = maxSize;
        for (int idx : endList)
        {
            int pre = idx;
            if (pre == 0)
            {
                return true;
            }
            for (int j = idx-1; j >= 0; j--)
            {
                if(dp[j][0]<=pre &&dp[j][1]>=pre)
                {
                    if(j==0){
                        return true;
                    }
                    else{
                        pre = j;
                    }

                }
                else if(j==0){
                    break;
                }
            }
        }
        return false;
    }

//方法二 官方解法
    bool canJump1(vector<int>& nums) {
        int target = nums.size() - 1;
        //从后往前遍历
        for (int i = nums.size() - 2; i >= 0;i--){
            if(i+nums[i]>=target){//如果该位置能到达target 则把target设为该位置
                target = i;
            }
        }
        if(target==0){
            return true;
        }
        else{
            return false;
        }
    }
};


int main()
{
    vector<int> nums{2,3,1,1,4};
    Solution s;
    cout << s.canJump1(nums) << '\n';
    return 0;
}
