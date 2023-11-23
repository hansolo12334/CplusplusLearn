#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//使用哈希表
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it!=hashtable.end())
            {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};


//两数之和
int main()
{
    vector<int> nums{-1,-2,-3,-4,-5};
    int target{-8};
    Solution s;
    vector<int> re{s.twoSum(nums, target)};

    for(int r:re)
    {
        std::cout << r << ' ';
    }
    std::cout << '\n';
    return 0;
}
