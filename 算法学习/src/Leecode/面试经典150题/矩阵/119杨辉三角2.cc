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
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> re;
        rowIndex = rowIndex + 1;
        for (int i = 0; i < rowIndex; i++)
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
        return re[rowIndex-1];
    }
};



int main()
{
    int rowIndex = 3;
    Solution s;
    auto re = s.getRow(rowIndex);
    for (auto rr:re)
    {
        cout << rr << ' ';
    }
    cout << '\n';
    return 0;
}
