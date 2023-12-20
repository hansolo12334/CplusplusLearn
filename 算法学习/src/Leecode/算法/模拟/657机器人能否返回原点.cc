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
    bool judgeCircle(string moves) {
        int lr{};
        int ud{};
        int fp{0};
        int ep = moves.size()-1;
        while(fp<ep)
        {
            getStep(moves[fp],lr,ud);
            getStep(moves[ep],lr,ud);
            fp++;
            ep--;
        }
        return (lr == 0 && ud == 0 ? true : false);
    }

    void getStep(char move,int &lr,int &ud)
    {
        if(move=='D')
        {
            ud++;
        }
        if(move=='U')
        {
            ud--;
        }
        if(move=='R')
        {
            lr++;
        }
        if(move=='L')
        {
            lr--;
        }
    }

};



int main()
{
    string moves{"UD"};
    Solution ss;
    cout << ss.judgeCircle(moves) << '\n';
    return 0;
}
