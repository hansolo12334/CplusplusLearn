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
//方法二 dfs 剪枝
    vector<string> goodsOrder(string goods)
    {
        dfs(goods, 0);
        return re;
    }
private:
    void dfs(string goods,int x)
    {
        if(x==goods.size()-1)
        {
            re.push_back(goods);
            return;
        }
        set<int> st;
        for (int i = x; i < goods.size();i++)
        {
            if(st.find(goods[i])!=st.end())//使用set 排除重复元素
            {
                continue;
            }
            st.insert(goods[i]);
            swap(goods[i], goods[x]);
            dfs(goods, x + 1);
            swap(goods[i], goods[x]);
        }
    }
    vector<string> re{};
};


int main()
{
    string goods{"agew"};
    Solution s;
    vector<string> re=s.goodsOrder(goods);
    for(string g:re)
    {
        cout << g << ' ';
    }
    cout << '\n';
    return 0;
}
