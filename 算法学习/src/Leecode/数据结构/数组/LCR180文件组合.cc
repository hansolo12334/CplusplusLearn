#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;




class Solution {
public:
    vector<vector<int>> fileCombination(int target) {

        vector<vector<int>> re;
        for (int i = 1; i <= (int)(target+1) / 2;i++)
        {
            vector<int> r;
            int sum{0};
            for (int j = i; j <=(int)(target+1) / 2; j++)
            {
                r.push_back(j);
                sum += j;
                if(sum>target)
                {
                    break;
                }
                if (sum==target)
                {
                    re.push_back(r);
                }
            }
        }
        return re;
    }


};





int main()
{
    Solution s;
    vector<vector<int>> re = s.fileCombination(18);
    for (vector<int> rr : re)
    {
        std::cout << '[';
        for (int r : rr)
        {
            std::cout << r << ", ";
        }
        std::cout << "],\n";
    }
    return 0;
}
