#include<iostream>
#include<vector>

#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
       std::vector<int> map{};
        for (size_t i = 0; i <=1000; i++)
        {
            map.push_back(0);
        }

        for (size_t i = 0; i < nums1.size(); i++)
        {
            ++map.at(nums1.at(i));
        }

        int k{0};
        std::vector<int> re{};
        for (auto item:nums2)
        {
            if(map.at(item)>0)
            {
                --map[item];
                re.push_back(item);
            }
        }
        return re;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums1{4,9,5};
    std::vector<int> nums2{9,4,9,8,4};

    std::vector<int> re{s.intersect(nums1, nums2)};

    for (size_t i = 0; i < re.size(); i++)
    {
        std::cout << re.at(i) << ' ';
    }

    std::cout << '\n';

    return 0;
}
