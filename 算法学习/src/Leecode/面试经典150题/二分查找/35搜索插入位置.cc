#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>
#include<map>
#include<unordered_set>


using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i<=j){
            int mid = (i + j) / 2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }

        return i;
    }
};



int main()
{
    vector<int> nums{1, 3, 5, 6};
    Solution s;
    int target = 7;
    cout << s.searchInsert(nums, target) << '\n';
    return 0;

}
