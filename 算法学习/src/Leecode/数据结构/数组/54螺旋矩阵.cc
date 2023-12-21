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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        int heading = 0;
        int i = 0, j = 0;
        vector<int> re{};
        while(re.size()!= height*width)
        {
            re.push_back(matrix[i][j]);
            matrix[i][j] = 101;
            //移动 撞墙转向
            if(heading==0) {
                j++;
            }
            if(heading==-90){
                i++;
            }
            if(heading==180){
                j--;
            }
            if(heading==90){
                i--;
            }

            //不管是撞墙 还是遇到已经走过的路 转向
            if(j>=width || (heading==0&&matrix[i][j]==101)){
                heading = -90;
                j--;
                i++;
            }
            if(j<0|| (heading==180 &&matrix[i][j]==101)){
                heading = 90;
                j++;
                i--;
            }
            if(i>=height|| (heading==-90&&matrix[i][j]==101)){
                heading = 180;
                i--;
                j--;
            }
            if(i<0|| (heading==90&&matrix[i][j]==101)){
                heading = 0;
                i++;
                j++;
            }
        }
        return re;
    }
};



int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution ss;
    vector<int> re = ss.spiralOrder(matrix);
    for(int r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
}
