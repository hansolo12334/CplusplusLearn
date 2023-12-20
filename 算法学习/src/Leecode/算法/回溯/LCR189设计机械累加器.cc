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
    int mechanicalAccumulator(int target) {
        target && (target += mechanicalAccumulator(target-1));
        return target;
    }
    int re=0;
};


int main()
{
    Solution s;
    int target = 5;
    int re=s.mechanicalAccumulator(target);
    cout << re << '\n';
    return 0;
}
