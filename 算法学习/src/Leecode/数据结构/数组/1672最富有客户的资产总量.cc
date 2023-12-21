#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        for (int i = 0; i < accounts[0].size()-1;i++)
        {
            for (int j = 0; j < accounts.size();j++)
            {
                accounts[j][i+1]+=accounts[j][i];
            }
        }
        int maxRich = accounts[0][accounts[0].size() - 1];
        for (int i = 0; i < accounts.size(); i++)
        {
            if(accounts[i][accounts[0].size()-1]>maxRich)
            {
                maxRich = accounts[i][accounts[0].size() - 1];
            }
        }
        return maxRich;
    }
};


int main()
{
    vector<vector<int>> accounts{{1, 2, 3}, {3, 2, 1}};
    Solution ss;
    cout << ss.maximumWealth(accounts) << '\n';
    return 0;
}
