#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>
#include<map>
#include<unordered_set>


using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        map<int, int> i2i{};
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            i2i[nums[i]] = i;
        }
        int maxSeqSize{0};
        int currentSeqSize{0};
        for (auto iter = i2i.begin(); iter != i2i.end();)
        {
            auto now = iter;
            iter++;
            auto next = iter;
            if (next != i2i.end() && (now->first + 1) == next->first)
            {
                currentSeqSize++;
            }
            else
            {
                if(maxSeqSize<currentSeqSize)
                {
                    maxSeqSize = currentSeqSize;
                }
                currentSeqSize = 0;
            }
        }

        return maxSeqSize+1;
    }


//方法二 官方解法 unordered_set
int longestConsecutive1(vector<int>& nums) {
    unordered_set<int> num_set{};
    for(const int &num:nums)
    {
        num_set.insert(num);
    }
    int maxSeqSize{0};
    for(const int &num:num_set)
    {
        if(!num_set.count(num-1))
        {
            int currentNum{num};
            int currentSeqSize{1};

            while(num_set.count(currentNum+1))
            {
                currentNum += 1;
                currentSeqSize++;
            }

            maxSeqSize = max(maxSeqSize, currentSeqSize);
        }
    }

    return maxSeqSize;
}
};


int main()
{
    vector<int> nums{0,3,7,2,5,8,4,6,0,1};
    Solution s;
    cout << s.longestConsecutive1(nums) << '\n';
    return 0;
}
