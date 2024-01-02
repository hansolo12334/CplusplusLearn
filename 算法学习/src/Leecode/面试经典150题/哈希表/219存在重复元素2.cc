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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map{};
        for (int i=0;i<n;i++)
        {
            if(!map.count(nums[i]))
            {
                map[nums[i]] = i;
            }
            else
            {
                if( (map[nums[i]]-i)*(map[nums[i]]-i)<=k*k)
                {
                    return true;
                }
                else
                {
                    map[nums[i]] = i;
                }
            }
        }
        return false;
    }
};


int main()
{
    vector<int> nums{1,0,1,1};
    int k{1};
    Solution s;
    cout << s.containsNearbyDuplicate(nums, k) << '\n';
    return 0;
}
