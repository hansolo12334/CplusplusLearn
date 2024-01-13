#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;


class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int, int> map;
        for (int i= 0; i <= static_cast<int>(sqrt(c));i++)
        {
            map[i*i] = i ;
        }
        for (auto iter = map.begin(); iter != map.end();iter++)
        {
            // cout << iter->first << '\n';
            if (map.find(c - iter->first) != map.end())
            {
                return true;
            }
        }

        return false;
    }
//方法二
    bool judgeSquareSum1(int c) {
        for (long a = 0; a * a <= c;a++){
            double b = c - (a * a);
            if(b==(int)b){
                return true;
            }
        }
        return false;
    }
};





int main()
{
    int c = 5;
    Solution s;
    cout << s.judgeSquareSum1(c) << '\n';
    return 0;
}
