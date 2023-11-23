#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum{0};
        std::vector<int> all{};

        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            all.push_back(sum);
        }

        if((sum-all[0])==0)
        {
            return 0;
        }

        for (size_t i = 0; i < nums.size()-1; i++)
        {

            if( (sum-all.at(i+1)) == all.at(i) )
            {
                return i+1;
            }
        }
        return -1;
    }
};

int main()
{
    std::vector<int> nums{-1,-1,0,0,-1,-1};
    Solution s;

    int re{s.pivotIndex(nums)};
    std::cout << re << '\n';
    return 0;
}
