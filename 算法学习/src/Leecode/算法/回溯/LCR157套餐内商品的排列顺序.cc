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

    vector<string> goodsOrder(string goods) {

        int sizeGoods = goods.size();
        vector<bool> visted(sizeGoods, false);
        //先对goods中的元素进行排序 使相同的元素挨在一起
        sort(goods.begin(), goods.end());
        for (int i = 0; i < goods.size();i++)
        {
            string temp{};
            recur(goods, i, visted, temp);
        }

        return re;
    }

    void recur(string &goods,int j, vector<bool> &visted,string &temp)
    {
        if(j<0||  j>=goods.size()||  visted[j]==true )
        {
            return;
        }


        temp += goods[j];
        if(temp.size()==goods.size())
        {
            re.push_back(temp);
        }

        visted[j] = true;

        int temp_j = j;

        for (int n = 0; n < goods.size();n++)
        {
            //如果相邻元素 相同  且已经访问了一次 就跳过
            if(visted[n] || (n>0&& visted[n-1]==true && goods[n-1]==goods[n]) )
            {
                continue;
            }
            recur(goods,  n, visted,temp);
        }

        visted[temp_j] = false;

        temp.pop_back();

    }

private:
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
