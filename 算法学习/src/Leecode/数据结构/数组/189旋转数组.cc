#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    void rotate(vector<int> &nums,int k)
    {


        int size = nums.size();
        if(size!=1 && size>k)
        {
            vector<int> re{};
            re.insert(re.end(), nums.end() - k, nums.end());
            re.insert(re.end(), nums.begin(), nums.end() - k);
            nums = re;
        }
        if (size<k)
        {
            k = k % size;
            rotate(nums, k);
        }
    }

//思路二 先反转所有元素 然后再反转前k个元素和后面的元素
    void rotate1(vector<int> &nums,int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k-1);
        reverse(nums, k , n - 1);
    }
    void reverse(vector<int> &nums,int fp,int ep)
    {
        while (fp < ep)
        {
            int temp = nums[fp];
            nums[fp] = nums[ep];
            nums[ep] = temp;
            fp++;
            ep--;

        }
    }
};



int main()
{
    vector<int> nums{1};
    int k{0};
    Solution s;
    s.rotate1(nums,k);

    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums.at(i) << " ";
    }
    std::cout << '\n';
    return 0;
}
