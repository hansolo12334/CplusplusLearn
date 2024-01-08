#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <unordered_set>
#include <string.h>


using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for (int i = 0; i < m;i++){
            for (int j = i; j <m;j++){
                if(i!=j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        for (int i = 0; i < m;i++){
            int end = m - 1;
            for (int j = 0; j < m / 2; j++)
            {
                swap(matrix[i][j], matrix[i][end]);
                end--;
            }
        }
    }
};


int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(matrix);
    for(auto mm :matrix){
        for(int m: mm){
            cout << m << ' ';
        }
        cout << '\n';
    }

    return 0;
}
