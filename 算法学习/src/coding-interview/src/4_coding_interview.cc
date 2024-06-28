#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>


//二维数组中的查找
class Solution
{
public:

    bool searchArray(std::vector<std::vector<int>> &vec,int target)
    {
        for (int i = 0; i < vec.size();i++)
        {
            if(binerySearch(vec[i],target))
            {
                return true;
            }
        }
        return false;

    }

    bool binerySearch(std::vector<int> &vec ,int target)
    {
        int i = 0;
        int j = vec.size() - 1;
        while(i<=j)
        {
            int mid = (i + j) / 2;
            if(vec[mid]>target)
            {
                i = mid + 1;
            }
            else if(vec[mid]<target){
                j = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }


    //正确解法 从矩阵右上角开始搜索
    bool searchArray1(std::vector<std::vector<int>> &vec,int target)
    {
        int i = vec.size();
        if(i<1){
            return false;
        }
        int j = vec[0].size() - 1;
        while(i<vec.size() && j>=0)
        {
            if(vec[i][j]==target)
            {
                return true;
            }
            if(vec[i][j]<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};



int main()
{
    std::vector<std::vector<int>> vec{
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
        };
    Solution ss;
    int target{6};
    std::cout << ss.searchArray1(vec, target) << '\n';
    return 0;
}
