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
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int maxLength = 0;
        int j = 0;
        for (int i = 0; i < nums.size();i++)
        {
            while (nums[i] - nums[j] > 1)
            {
                j++;
            }

            if (nums[i] - nums[j] == 1)
            {
                if (maxLength < (i - j + 1))
                {
                    maxLength = i - j + 1;
                }
            }
        }
        return maxLength;
    }
};


int main()
{
    vector<int> nums{1,1,2,2,3,3};
    Solution s;
    cout << s.findLHS(nums) << '\n';
    return 0;
}
