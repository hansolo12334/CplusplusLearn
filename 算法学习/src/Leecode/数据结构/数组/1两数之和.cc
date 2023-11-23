#include<iostream>
#include<vector>


using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        if(nums.size()==2){
            return {0, 1};
        }


        std::vector<int> re;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            // if(nums[i]>target)
            // {
            //     continue;
            // }
            for (size_t j=i+1; j < nums.size(); j++)
            {
                if(nums.at(i)+nums.at(j)==target)
                {
                    re.push_back(i);
                    re.push_back(j);
                    break;
                }
            }
        }
        return re;
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
