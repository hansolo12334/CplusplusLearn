#include<iostream>
#include<algorithm>
#include<vector>



class Solution
{
public:
    Solution(){}

    int mValue = 0;


    void recur(int i, int j, std::vector<std::vector<int>> &map, int value)
    {
        if(i>=map.size() || j>=map[i].size()){
            return;
        }
        value += map[i][j];
        if(i==map.size()-1 && j==map[i].size()-1){
            mValue = value > mValue ? value : mValue;
            std::cout << value << '\n';
        }
        recur(++i, j, map,value);
        --i;
        recur(i, ++j, map, value);
    }

    int maxValue(std::vector<std::vector<int>> &map)
    {
        int value = 0;
        recur(0, 0, map,value);
        return mValue;
    }


    //dp
    int maxValue1(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));

        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n;++j){
                if(i>0){
                    dp[i][j] = std::max(grid[i][j] + dp[i - 1][j], dp[i][j]);
                }
                if(j>0){
                    dp[i][j] = std::max(grid[i][j] + dp[i][j-1], dp[i][j]);
                }

            }
        }

        return dp[m - 1][n - 1];
    }
};


int main()
{
    std::vector<std::vector<int>> map{
        {2,3,1},
        {1,7,1},
        {4,6,1}
        };

    Solution ss;
    std::cout << ss.maxValue1(map) << '\n';
    return 0;
}
