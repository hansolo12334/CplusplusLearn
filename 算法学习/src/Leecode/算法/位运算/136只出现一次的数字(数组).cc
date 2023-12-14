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
    vector<int> nums{2, 2, 1};
    Solution s;
    cout << s.singleNumber(nums) << '\n';
    return 0;
}
