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
//  位运算  成对的两个相同的数字亦或 为0 ，所以遍历一遍，只剩下了单个的数字。
    int singleNumber(vector<int>& nums) {
        int re{};
        for (size_t i = 0; i < nums.size();i++)
        {
            re ^= nums[i];
        }
        return re;
    }
};





int main()
{
    vector<int> nums{11,11, 2, 13,13};
    Solution s;
    cout << s.singleNumber(nums) << '\n';
    return 0;
}
