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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> map;
        vector<int> re;
        for (int n1 : nums1)
        {
            map[n1]++;
        }
        for(int n2:nums2)
        {
            if(map[n2]>=1){
                re.push_back(n2);
                map[n2]=0;
            }
        }
        return re;
    }
};


int main()
{
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};
    Solution ss;
    vector<int> re = ss.intersection(nums1, nums2);
    for(int r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
