#include<vector>
#include<iostream>
#include<algorithm>



class Solution
{
public:
    Solution(){}

    std::vector<int> minKNums(std::vector<int> &vec,int k)
    {
        if(vec.size()<=0)
        {
            return {};
        }
        std::sort(vec.begin(), vec.end());
        return {vec.begin(), vec.begin() + k};
    }
};



int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8};

    Solution ss;
    int k = 4;
    auto re = ss.minKNums(vec, k);

    for(auto r:re)
    {
        std::cout << r << ' ';
    }
    std::cout << '\n';
    return 0;
}
