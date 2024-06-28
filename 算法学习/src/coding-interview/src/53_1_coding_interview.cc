#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>


class Solution
{
public:
    int getNumberOfK(std::vector<int> vec,int n)
    {
        int ptail = vec.size()-1;
        int phead = 0;
        while(vec[ptail]!=n){
            ptail--;
        }
        //如果ptail减到了0都搜索不到，说明数组中没有该元素 提前退出
        if(ptail<=0){
            return 0;
        }
        while(vec[phead]!=n){
            phead++;
        }
        return ptail - phead+1;
    }
};


int main()
{
    std::vector<int> vec{1, 2, 3, 3, 3, 3, 4, 5};
    int n{3};
    Solution s;
    std::cout << s.getNumberOfK(vec, n) << '\n'; return 0;
}
