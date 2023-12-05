#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int j{0};
        int n=nums.size();
        for (size_t i = 0; i < n; i++)
        {
            if(nums[i]!=val)
            {
                nums[j] = nums[i];
                j++;
            }
        }


        return j;
    }
};






int main()
{
    vector<int> nums{0,1,2,2,3,0,4,2};
    int val{2};
    Solution s;
    int len=s.removeElement(nums,val);

    for (int i = 0; i < len;i++)
    {
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}
