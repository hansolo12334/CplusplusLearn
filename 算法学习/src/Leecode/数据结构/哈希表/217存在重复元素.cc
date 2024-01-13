#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size();i++){
            map[nums[i]]++;
        }
        bool flag = false;
        for (auto iter = map.begin(); iter != map.end(); iter++)
        {
            if(iter->second>=2){
                flag = true;
            }
        }
        return flag;
    }

//
    bool containsDuplicate1(vector<int>& nums) {
        if(nums.size()<=1){
            return false;
        }
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }

};



int main()
{
    vector<int> nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    Solution ss;
    cout << ss.containsDuplicate1(nums) << '\n';
    return 0;
}
