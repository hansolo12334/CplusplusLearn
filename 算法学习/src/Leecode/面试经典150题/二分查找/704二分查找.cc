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
    int search(vector<int>& nums, int target) {

        int re = 0;
        int i = 0;
        int j=nums.size()-1;

        while(i<=j){
            int mid = (i + j) / 2;
            if(target>nums[mid]){
                i = mid+1;
            }
            else if(target<nums[mid]){
                j = mid - 1;
            }
            else if(target==nums[mid]){
                return mid;
            }
        }

        return -1;
    }
};


int main()
{
    vector<int> nums{5};
    Solution s;
    int target = 5;
    cout << s.search(nums, target) << '\n';
    return 0;
}
