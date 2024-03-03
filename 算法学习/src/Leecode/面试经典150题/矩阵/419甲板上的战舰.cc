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
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n = board[0].size();

        int re = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n;j++)
            {
                if(board[i][j]=='X')
                {
                    board[i][j] = '.';
                    for (int k = j + 1; k < n &&board[i][k]=='X'; k++)
                    {
                        board[i][k] = '.';
                    }
                    for (int k = i + 1; k < m && board[k][j] == 'X'; k++)
                    {
                        board[k][j] = '.';
                    }
                    re++;
                }
            }
        }
        return re;
    }
};


int main()
{
    vector<vector<char>> board = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    Solution s;
    cout << s.countBattleships(board) << '\n';
    return 0;
}
