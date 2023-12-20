#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

#include <deque>
#include <queue>

#include<set>

using namespace std;


class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {

        vector<vector<int>> map(3, vector<int>(3, 0));
        string re{};
        int i{};
        for (i = 0; i < moves.size(); i++)
        {
            int m = moves[i][0];
            int n = moves[i][1];
            if (i % 2 == 0)
            {
                //A 走
                map[m][n] = 1;
            }
            else
            {
                //B走
                map[m][n] = -1;
            }
            if(i>=4)
            {
                if(checkWinner(map) && i%2==0)
                {
                    return "A";
                }
                else if(checkWinner(map) && i%2==1)
                {
                    return "B";
                }
            }
        }
        if(i==9)
        {
            return "Draw";
        }
        return "Pending";
    }

    bool checkWinner(vector<vector<int>> &map)
    {
        if(checkLine(map, 3) || checkLine(map, -3) )
        {
            return true;
        }
        return false;
    }

    bool checkLine(vector<vector<int>> &map,int num)
    {
        //行
        if(map[0][0]+map[0][1]+map[0][2]==num)
        {
            return true;
        }
        else if(map[1][0]+map[1][1]+map[1][2]==num)
        {
            return true;
        }
        else if(map[2][0]+map[2][1]+map[2][2]==num)
        {
            return true;
        }
        //列
        else if(map[0][0]+map[1][0]+map[2][0]==num)
        {
            return true;
        }
        else if(map[0][1]+map[1][1]+map[2][1]==num)
        {
            return true;
        }
        else if(map[0][2]+map[1][2]+map[2][2]==num)
        {
            return true;
        }
        //对角线
        else if(map[0][0]+map[1][1]+map[2][2]==num)
        {
            return true;
        }
        else if(map[0][2]+map[1][1]+map[2][0]==num)
        {
            return true;
        }
        return false;
    }
};


int main()
{
    vector<vector<int>> moves{{0,0},{2,0},{1,1},{2,1},{2,2}};
    Solution ss;
    cout << ss.tictactoe(moves) << '\n';
    return 0;
}
