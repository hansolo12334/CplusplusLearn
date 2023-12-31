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

//方法一 双指针
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size();
        if(j==2)
        {
            return {1, 2};
        }
        j--;
        for (int i = 0; i < j; i++)
        {
            while(numbers[i]+numbers[j]>target)
            {
                j--;
            }
            if(numbers[i]+numbers[j]==target)
            {
                return {i + 1, j + 1};
            }
        }
        return {0, 0};
    }
//方法二 二分法
    vector<int> twoSum1(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size();i++)
        {
            int low = i - 1;
            int high=numbers.size()-1;

            while(low<high)
            {
                int mid = (low + high) / 2;
                if(numbers[mid]==target-numbers[low])
                {
                    return {low + 1, mid + 1};
                }
                else if(numbers[mid]>target-numbers[low])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return {0, 0};
    }
};


int main()
{
    vector<int> number{2, 7, 11, 15};
    int target{9};
    Solution s;
    vector<int> re = s.twoSum1(number, target);
    for(int r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;

}
