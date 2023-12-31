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
// 双指针 贪心算法
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maxA = 0;
        while (i < j)
        {
            //思路 每次只向内移动短板
            int minV = min(height[i], height[j]);
            int S = minV * (j - i);
            if (S > maxA)
            {
                maxA = S;
            }
            if(height[i]==minV)
            {
                i++;
            }
            else{
                j--;
            }
        }
        return maxA;
    }
};

int main()
{
    vector<int> height{2,3,4,5,18,17,6};
    Solution ss;
    cout << ss.maxArea(height) << '\n';
    return 0;
}
