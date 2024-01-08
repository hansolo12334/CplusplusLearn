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
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> smaps(9, unordered_map<int, int>());
        vector<unordered_map<int, int>> bmapsRows(9, unordered_map<int, int>());//行
        vector<unordered_map<int, int>> bmapsColums(9, unordered_map<int, int>());//列
        int a = 0;
        int b = 0;
        for (int i = 0; i < board.size(); i++)
        {

            for (int j = 0; j < board.size(); j++)
            {
                if(board[i][j]>='0' && board[i][j]<='9'){

                    bmapsRows[i][board[i][j]]++;
                    bmapsColums[j][board[i][j]]++;
                    if(bmapsColums[j][board[i][j]]>=2){
                        return false;
                    }
                    if(bmapsRows[i][board[i][j]]>=2){
                        return false;
                    }

                    int index = (i / 3) * 3 + (j / 3);
                    smaps[index][board[i][j]]++;
                    if(smaps[index][board[i][j]]>=2){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    //官方解法
    bool isValidSudoku1(vector<vector<char>>& board) {

        int rows[9][9];
        int columns[9][9];
        int subboxes[3][3][9];

        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(subboxes, 0, sizeof(subboxes));

        for (int i = 0; i < 9;i++){
            for (int j = 0; j < 9;j++){
                char c = board[i][j];
                if(c!='.'){
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    columns[j][index]++;
                    subboxes[i / 3][j / 3][index]++;
                    if(rows[i][index]>1 || columns[j][index]>1 || subboxes[i / 3][j / 3][index]>1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    cout << s.isValidSudoku1(board) << '\n';
    return 0;
}
