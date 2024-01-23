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
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num:nums)
        {
            map[num]++;
        }
        vector<int> re;
        for (auto [num, s] : map)
        {
            if(s==2)
            {
                re.push_back(num);
            }
        }
        return re;
    }
};



int main()
{
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    Solution s;
    vector<int> re = s.findDuplicates(nums);

    for(int r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
