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
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
        {
            return n;
        }
        int slow = 2;
        int fast = 2;
        while(fast<n)
        {
            if (nums[slow-2]!=nums[fast])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};


int main()
{
    vector<int> nums{1,1,1,2,2,3};
    Solution s;
    cout << s.removeDuplicates(nums) << '\n';

    for(int n: nums)
    {
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}
