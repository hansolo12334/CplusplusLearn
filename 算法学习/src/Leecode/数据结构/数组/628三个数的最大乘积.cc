#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;


class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<>());
        int n = nums.size() - 1;
        return max( nums[n] * nums[n - 1] * nums[0], nums[0] * nums[1] * nums[2] );
    }
};


int main()
{
    vector<int> nums{1, 2, 3};
    Solution s;
    cout << s.maximumProduct(nums) << '\n';
    return 0;
}
