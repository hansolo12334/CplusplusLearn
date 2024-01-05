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
    //官方方法 双指针
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }
        int slow = 2;
        int fast = 2;
        while (fast < n)
        {
            if (nums[slow - 2] != nums[fast])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
    // 计数法
    int removeDuplicates1(vector<int> &nums)
    {
        int n = nums.size();
        int idx = 0;  // idx是一个慢指针 表示处理好的字符串长度 也是最终返回的字符串长度
        int preNum = INT_MAX;
        int cnt = 0; //重复数的数量
        for (int i = 0; i < n; i++)
        {
            cnt++;
            if (nums[i] != preNum)//遇到新的和前面不一样的 数字 重新开始计数
            {
                nums[idx] = nums[i];
                idx++;
                cnt = 1; //     cnt 初始化为 1
            }
            else// 前后两个数字相同 判断是否重复两次
            {
                if (cnt <= 2)  // 如果 当前数字计数<=2 进入交换
                {
                    nums[idx] = nums[i];
                    idx++;
                }
            }
            preNum = nums[i];
        }
        return idx;
    }
};


int main()
{
    vector<int> nums{1, 1, 2, 3, 3, 3,4};
    Solution s;
    cout << s.removeDuplicates1(nums) << '\n';

    for (int n : nums)
    {
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}
