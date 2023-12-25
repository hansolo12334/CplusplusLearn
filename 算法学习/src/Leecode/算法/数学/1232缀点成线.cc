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
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int nums=coordinates.size();
        for (int i = 1; i < nums-1; i++)
        {
            if (((coordinates[i][0] - coordinates[i - 1][0]) == 0
                     ? 90
                     : static_cast<double>(coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0])) !=
                ((coordinates[i + 1][0] - coordinates[i][0]) == 0
                     ? 90
                     : static_cast<double>(coordinates[i + 1][1] - coordinates[i][1]) / (coordinates[i + 1][0] - coordinates[i][0])))
            {
                return false;
            }
        }
        return true;
    }

    //方法二 向量法
    bool checkStraightLine1(vector<vector<int>>& coordinates) {
        int deltaX = coordinates[0][0];
        int deltaY = coordinates[0][1];
        int n = coordinates.size();

        for (int i = 0; i < n;i++){
            coordinates[i][0] -= deltaX;
            coordinates[i][1] -= deltaY;
        }
        int firstVX = coordinates[0][0];
        int firstVY = coordinates[0][1];
        for (int i = 1; i < n;i++)
        {
            int Vx = coordinates[i][0];
            int Vy = coordinates[i][1];
            if(Vx*firstVX+Vy*firstVY !=0)//向量平行
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    vector<vector<int>> coordinates = {{-4, -3}, {1, 0}, {3, -1}, {0, -1}, {-5, 2}};
    Solution ss;
    cout << ss.checkStraightLine1(coordinates) << '\n';
    return 0;
}
