#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <map>
#include <math.h>
#include <set>
#include <string.h>
#include <string>
#include <unordered_set>


using namespace std;


class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        auto new_board = board;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(judgeLD(i,j,m,n,board)){
                    new_board[i][j]=1;
                }
                else{
                    new_board[i][j]=0;
                }
            }
        }
        board = new_board;
    }



    bool judgeLD(int i, int j, int m, int n, vector<vector<int>> &board)
    {
        int live = 0;
        int dead = 0;
        //左上
        if ((i - 1) >= 0 && (j - 1) >= 0)
        {
            if (board[i - 1][j - 1])
            {
                live++;
            }
            else
            {
                dead++;
            }
        }
        //右下
        if ((i + 1) < m && (j + 1) < n)
        {
            if (board[i + 1][j + 1])
            {
                live++;
            }
            else
            {
                dead++;
            }
        }
        //右上
        if ((i - 1) >= 0 && (j + 1) < n)
        {
            if (board[i - 1][j + 1])
            {
                live++;
            }
            else
            {
                dead++;
            }
        }
        //左下
        if ((i + 1) < m && (j - 1) >= 0)
        {
            if (board[i + 1][j - 1])
            {
                live++;
            }
            else
            {
                dead++;
            }
        }
        //上
        if ((i - 1) >= 0)
        {
            if (board[i - 1][j])
            {
                live++;
            }
            else
            {
                dead++;
            }
        }
        //下
        if ((i + 1) < m)
        {
            if (board[i + 1][j])
            {
                live++;
            }
            else
            {
                dead++;
            }
        }
        //左
        if ((j - 1) >= 0)
        {
            if (board[i][j - 1])
            {
                live++;
            }
            else
            {
                dead++;
            }
        }
        //右
        if ((j + 1) < n)
        {
            if (board[i][j + 1])
            {
                live++;
            }
            else
            {
                dead++;
            }
        }


        if(live<2 && board[i][j]){
            return false;
        }
        if(board[i][j] &&(live==2||live==3)){
            return true;
        }
        if(board[i][j]&& live>3){
            return false;
        }
        if(!board[i][j]&& live==3){
            return true;
        }
        return false;
    }


    //第二种方法 不复制矩阵 但是再设置一个状态 来表示它之前的状态
    void gameOfLife1(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool isdl = judgeLD1(i, j, m, n, board);
                if(!board[i][j] && isdl){ //死而复生
                    board[i][j]=2;
                }
                else if(board[i][j] && !isdl) //从生到死
                {
                    board[i][j] = -1;
                }
            }
        }


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(board[i][j] ==2){ //死而复生
                    board[i][j]=1;
                }
                else if(board[i][j] ==-1) //从生到死
                {
                    board[i][j] = 0;
                }
            }
        }

    }
    bool judgeLD1(int i, int j, int m, int n, vector<vector<int>> &board)
    {
        int live = 0;
        int dead = 0;
        //左上
        if ((i - 1) >= 0 && (j - 1) >= 0)
        {
            if (board[i - 1][j - 1]==1 || board[i - 1][j - 1]==-1 )
            {
                live++;
            }
            else if(board[i - 1][j - 1]==0 || board[i - 1][j - 1]==2)
            {
                dead++;
            }
        }
        //右下
        if ((i + 1) < m && (j + 1) < n)
        {
            if (board[i + 1][j + 1]==1 || board[i + 1][j + 1]==-1)
            {
                live++;
            }
            else if(board[i + 1][j + 1]==0 || board[i + 1][j + 1]==2)
            {
                dead++;
            }
        }
        //右上
        if ((i - 1) >= 0 && (j + 1) < n)
        {
            if (board[i - 1][j + 1]==1 || board[i - 1][j + 1]==-1)
            {
                live++;
            }
            else if (board[i - 1][j + 1]==0 || board[i - 1][j + 1]==2)
            {
                dead++;
            }
        }
        //左下
        if ((i + 1) < m && (j - 1) >= 0)
        {
            if (board[i + 1][j - 1]==1 ||board[i + 1][j - 1]==-1  )
            {
                live++;
            }
            else if (board[i + 1][j - 1]==0 ||board[i + 1][j - 1]==2  )
            {
                dead++;
            }
        }
        //上
        if ((i - 1) >= 0)
        {
            if (board[i - 1][j]==1 ||board[i - 1][j]==-1)
            {
                live++;
            }
            else if(board[i - 1][j]==0 ||board[i - 1][j]==2)
            {
                dead++;
            }
        }
        //下
        if ((i + 1) < m)
        {
            if (board[i + 1][j]==1 || board[i + 1][j]==-1)
            {
                live++;
            }
            else if(board[i + 1][j]==0 || board[i + 1][j]==2)
            {
                dead++;
            }
        }
        //左
        if ((j - 1) >= 0)
        {
            if (board[i][j - 1]==1 ||board[i][j - 1]==-1 )
            {
                live++;
            }
            else if (board[i][j - 1]==0 ||board[i][j - 1]==2 )
            {
                dead++;
            }
        }
        //右
        if ((j + 1) < n)
        {
            if (board[i][j + 1]==1 ||board[i][j + 1]==-1 )
            {
                live++;
            }
            else if(board[i][j + 1]==0 ||board[i][j + 1]==2 )
            {
                dead++;
            }
        }


        if(live<2 && board[i][j]){
            return false;
        }
        if(board[i][j] &&(live==2||live==3)){
            return true;
        }
        if(board[i][j]&& live>3){
            return false;
        }
        if(!board[i][j]&& live==3){
            return true;
        }
        return false;
    }
};


int main()
{
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution s;
    s.gameOfLife1(board);
    for (auto mm : board)
    {
        for (int m : mm)
        {
            cout << m << ' ';
        }
        cout << '\n';
    }

    return 0;
}
