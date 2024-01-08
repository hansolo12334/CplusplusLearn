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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNum = 0;
        int now = 0;
        for (int i = 0; i < nums.size();i++){
            if(nums[i]==1){
                now++;
                if(maxNum<now){
                    maxNum = now;
                }
            }
            else{
                now = 0;
            }

        }
        return maxNum;
    }
};


int main()
{
    vector<int> nums{1, 1, 0, 1, 1, 1};
    Solution s;
    cout << s.findMaxConsecutiveOnes(nums) << '\n';
    return 0;
}
