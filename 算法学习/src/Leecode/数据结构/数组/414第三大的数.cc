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
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int time = 0;
        int minNum = INT_MAX;
        for (int i = nums.size()-1; i >=0; i--)
        {
            if(nums[i]==INT_MAX || nums[i]< minNum){
                minNum = nums[i];
                time++;
                if (time >= 3){
                    return minNum;
                }
            }
        }
        return nums[nums.size()-1];
    }
};


int main()
{
    vector<int> nums{1,2147483647,-2147483648};
    Solution s;
    cout << s.thirdMax(nums) << '\n';
    return 0;
}
