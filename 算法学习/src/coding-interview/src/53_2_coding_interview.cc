#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>


class Solution
{
public:
    int getMissingNumber(std::vector<int> &vec)
    {
        int v_size = vec.size();
        int i{0};
        for (; i < v_size; i++)
        {
            if(vec[i]!=i){
                return i;
            }
        }
        if(i==v_size){
            return vec[v_size - 1] + 1;
        }
        return 0;
    }
    int getMissingNumber1(std::vector<int> &vec)
    {
        int i{0};
        int j{vec.size() - 1};

        while(i<=j){
            int mid = (j + i) / 2;
            if(vec[mid]==mid){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }
        return i;
    }
};


int main()
{
    std::vector<int> vec{0,1,2,4};
    Solution s;
    std::cout << s.getMissingNumber1(vec) << '\n';
    return 0;
}
