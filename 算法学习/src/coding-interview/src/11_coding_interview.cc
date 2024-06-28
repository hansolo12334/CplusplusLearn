#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>


//旋转数组的最小数字
class Solution
{
public:
    int findMin(std::vector<int> &vec,int i ,int j)
    {



        //单调递增数列
        if(vec[i]<=vec[j]){
            return vec[i];
        }


        while(j-i>1)
        {
            int mid = (i + j) / 2;
            if(vec[i]==vec[j] && vec[mid]==vec[i]){
                return findMin(vec, i, j);
            }
            if(vec[mid]>=vec[i])
            {
                i = mid;
            }
            else if(vec[mid]<=vec[j])
            {
                j = mid;
            }
        }
        return vec[j];
    }
};



int main()
{
    std::vector<int> vec{2, 2, 2, 0, 1};
    Solution ss;
    int i = 0;
    int j = vec.size() - 1;
    std::cout << ss.findMin(vec,i,j) << '\n';
    return 0;
}
