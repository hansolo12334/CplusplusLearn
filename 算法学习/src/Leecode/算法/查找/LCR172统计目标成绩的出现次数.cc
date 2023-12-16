
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

#include <deque>
#include <queue>


using namespace std;



class Solution {
public:
//暴力遍历
    int countTarget(vector<int>& scores, int target) {
        int re{0};
        for (int i = 0; i < scores.size();i++)
        {
            if(scores[i]==target)
            {
                re++;
            }
        }
        return re;
    }
// 双指针
        int countTarget1(vector<int>& scores, int target) {
        if(scores.size()==0)
        {
            return 0;
        }
        int i{0};
        int j=scores.size()-1;
        while(1)
        {
            if(i>j)
            {
                return 0;
            }
            if(scores[i]==target &&scores[j]==target)
            {
                return j - i+1;
            }

            if(scores[i]!=target) {
                i++;
            }
            if(scores[j]!=target) {
                j--;
            }
        }
    }
//由于顺序是递增的 使用二分法 同同时查找左右边界
int countTarget2(vector<int>& scores, int target) {
    int leftIndex{};
    int rightIndex{};
    leftIndex = binarySearch(scores, target, true);
    rightIndex = binarySearch(scores, target, false) - 1;
    if(leftIndex<=rightIndex && rightIndex<scores.size() && scores[leftIndex]==target &&scores[rightIndex]==target)
    {
        return rightIndex - leftIndex + 1;
    }
    return 0;
}
int binarySearch(vector<int> &nums,int target, bool lower)
{
    int left = 0;
    int right = nums.size() - 1;
    int re = nums.size();

    while(left<=right)
    {
        int mid = (right + left) / 2;
        if(nums[mid]>target || (lower && nums[mid]>=target))
        {
            right = mid - 1;
            re = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return re;
}
};


int main()
{
    vector<int> scores{1};
    Solution s;
    int target{0};
    cout << s.countTarget2(scores,target) << '\n';
    return 0;
}
