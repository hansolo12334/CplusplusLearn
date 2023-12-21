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
    int diagonalSum(vector<vector<int>>& mat) {

        int re{0};
        for (int i = 0; i < mat.size(); i++)
        {
            int j = mat.size() - i - 1;
            if(j!=i)
            {
                re += mat[i][i] + mat[i][j];
            }
            else
            {
                re += mat[i][i];
            }
        }
        return re;
    }
};



int main()
{
    // vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> mat = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    vector<vector<int>> mat = {{5}};
    Solution ss;
    cout << ss.diagonalSum(mat) << '\n';
    return 0;
}
