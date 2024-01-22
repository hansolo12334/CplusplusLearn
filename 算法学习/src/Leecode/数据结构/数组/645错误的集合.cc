#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;



class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // unordered_map<int, int> map;

        int *map = new int[nums.size() + 1]{};
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        vector<int> re{0, 0};

        for (int i = 1; i <= nums.size(); i++)
        {
            if(map[i]>=2)
            {
                re[0] = i;
            }

            if (map[i]==0)
            {
                re[1] = i;
            }
            if(re[0]!=0&&re[1]!=0)
            {
                return re;
            }
        }
        return {};
    }
};



int main()
{
    vector<int> nums{1, 2, 2, 4};
    Solution s;
    vector<int> re = s.findErrorNums(nums);
    for(int r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
