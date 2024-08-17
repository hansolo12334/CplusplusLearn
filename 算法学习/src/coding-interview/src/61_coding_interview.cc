#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<math.h>




class Solution
{
public:
    Solution(){}

    bool isShunZi(std::vector<int> &vec)
    {
        if(vec.size()<=0)
        {
            return false;
        }
        std::sort(vec.begin(), vec.end());

        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            if(vec[i]==0)
            {
                cnt++;
                continue;
            }
            if(vec[i]==vec[i+1] && vec[i]!=0)
            {
                return false;
            }
            if(vec[i]+1!=vec[i+1])
            {
                cnt=cnt-vec[i+1]+vec[i]+1;
            }

        }
        return cnt==0;
    }
};

int main()
{
    std::vector<int> vec{1, 0, 0, 1, 5};
    Solution ss;
    std::cout << ss.isShunZi(vec) << '\n';
    return 0;
}
