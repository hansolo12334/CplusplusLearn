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


using namespace std;


class Solution {
public:

//方法一 深度优先遍历（DFS） 朝一个方向走到底 再回退
    int wardrobeFinishing(int m, int n, int cnt) {
        vector<vector<bool>> map(m, vector<bool>(n,false));
        return dfs_search(0, 0, m, n, cnt, 0 ,map);
    }

    int dfs_search(int i,int j,int m,int n,int cnt,int sums, vector<vector<bool>> &map)
    {
        if(i<0|| i>=m || j<0|| j>=n || (i/10 + i%10 + j/10 +j%10)>cnt || map[i][j])
        {
            return 0;
        }

        map[i][j] = true;
        int re = dfs_search(i + 1, j, m, n, cnt, sums, map) + dfs_search(i, j + 1, m, n, cnt, sums, map) +
                 dfs_search(i - 1, j, m, n, cnt, sums, map) + dfs_search(i, j - 1, m, n, cnt, sums, map)+1;
        return re;
    }
//方法二 广度优先遍历（BFS）  平推
int wardrobeFinishing1(int m, int n, int cnt) {
    vector<vector<bool>> visted(m, vector<bool>(n, false));
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    int re{0};
    while (!que.empty())
    {
        auto temp = que.front();
        que.pop();
        if( temp.first>=m||temp.second>=n || (temp.first/10 +temp.first%10 +temp.second/10+temp.second%10)>cnt || visted[temp.first][temp.second])
        {
            continue;
        }
        re++;
        visted[temp.first][temp.second] = true;
        que.push(make_pair(temp.first + 1, temp.second));
        que.push(make_pair(temp.first, temp.second + 1));
    }
    return re;
}
};


int main()
{
    int m = 4;
    int n = 7;
    int cnt = 5;
    Solution s;
    cout << s.wardrobeFinishing1(m, n, cnt) << '\n';
    return 0;
}
