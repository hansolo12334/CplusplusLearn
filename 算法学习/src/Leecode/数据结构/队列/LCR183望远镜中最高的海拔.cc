#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

#include<queue>

using namespace std;


class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        if(heights.empty())
        {
            return {};
        }
        vector<int> re{};
        auto hp{heights.begin()};
        while(hp<heights.end()-limit+1)
        {
            re.push_back(*max_element(hp, hp + limit));
            hp++;
        }
        return re;
    }
    //方法二 优先队列
    vector<int> maxAltitude1(vector<int>& heights, int limit) {
        auto n{heights.size()};
        if(n==0)
        {
            return {};
        }

        priority_queue<pair<int, int>> q;
        for (int i = 0; i < limit;i++)
        {
            q.emplace(heights[i], i);
        }
        vector<int> ans{q.top().first};
        for (int i = limit; i < n;i++)
        {
            q.emplace(heights[i], i);
            while(q.top().second<=i-limit)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};


int main()
{
    vector<int> heights{14, 2, 27, -5, 28, 13, 39};
    int limit{3};
    Solution s;
    vector<int> re = s.maxAltitude1(heights, limit);
    for(int r:re)
    {
        cout << r << ' ';
    }
    cout<<'\n';
    return 0;
}
