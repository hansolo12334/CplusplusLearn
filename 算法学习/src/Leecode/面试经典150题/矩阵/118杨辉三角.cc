#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>



using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> re;
        for (int i = 0; i < numRows;i++)
        {
            vector<int> temp;
            for (int j = 0; j <= i; j++)
            {
                if(j==0||j==i)
                {
                    temp.push_back(1);
                }
                else
                {
                    temp.push_back(re[i - 1][j - 1] + re[i - 1][j]);
                }
            }
            re.push_back(temp);
        }
        return re;
    }
};



int main()
{
    int numRows = 5;
    Solution s;
    auto re = s.generate(numRows);
    for (auto rr:re)
    {
        for(auto r:rr)
        {
            cout << r << ' ';
        }
        cout << '\n';
    }
    return 0;
}
