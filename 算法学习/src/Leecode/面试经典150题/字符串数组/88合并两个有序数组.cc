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

//原地算法
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        int edge = m - 1;
        for (int i = 0; i < n; i++)
        {
            while(nums2[i]>nums1[j]&& j<=edge)
            {
                j++;
            }
            for (int l = edge; l >= j;l--)
            {
                nums1[l + 1] = nums1[l];
            }
            nums1[j] = nums2[i];
            edge++;
        }
    }

//方法二 从后往前 两个数组分别比较 大的先移到 nums1右端
void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int edge = m + n - 1;
    m = m - 1;
    n = n - 1;
    while (n >= 0)
    {
       while(m>=0 && nums1[m]>nums2[n])
        {
            swap(nums1[edge--], nums1[m--]);

        }
        swap(nums1[edge--], nums2[n--]);
        }
}
};




int main()
{
    vector<int> nums1{-1,0,0,3,3,3,0,0,0};
    vector<int> nums2{1,2,2};
    int m{6};
    int n{3};
    Solution ss;
    ss.merge1(nums1, m, nums2, n);
    for(int n:nums1)
    {
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}
