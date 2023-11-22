#include<iostream>
#include<vector>

#include <algorithm>

using namespace std;

class Solution //如果给定的数组排好序了
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {

        std::vector<int> re{};

        auto p1{nums1.begin()};
        auto p2{nums2.begin()};

        while (p1!=nums1.end() && p2!=nums2.end())
        {
            if (*p1==*p2)
            {
                re.push_back(*p1);
                p1++;
                p2++;
            }
            else if (*p1<*p2)
            {
                p1++;
            }
            else
            {
                p2++;
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
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    std::vector<int> re{s.intersect(nums1, nums2)};

    for (size_t i = 0; i < re.size(); i++)
    {
        std::cout << re.at(i) << ' ';
    }

    std::cout << '\n';

    return 0;

}
