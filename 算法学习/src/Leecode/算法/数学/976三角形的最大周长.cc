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


class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // if(nums.size()==3){
        //     return (nums[0] + nums[1] > nums[2]) ? 1 : 0;
        // }
        int maxC = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if ((nums[i] + nums[i + 1]) > nums[i + 2])
            {
                if (maxC < (nums[i] + nums[i + 1] + nums[i + 2]))
                {
                    maxC = nums[i] + nums[i + 1] + nums[i + 2];
                }
            }
        }
        return maxC;
    }
    //  从大到小 的话  第一个遇到的组成三角形的变长就是最大值！！！ 比顺序快！！！
    int largestPerimeter1(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxC = 0;
        for (int i = nums.size() - 1; i >= 2; i--)
        {
            if ((nums[i - 2] + nums[i - 1]) > nums[i])
            {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
};


int main()
{
    vector<int> nums{2, 1, 2};
    Solution s;
    cout << s.largestPerimeter1(nums) << '\n';
    return 0;
}
