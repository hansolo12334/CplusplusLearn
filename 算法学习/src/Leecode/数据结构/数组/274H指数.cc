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
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(),std::greater<int>());
        int n = citations.size();
        int h = 0;
        for (int i = 0; i<n;i++)
        {
            if (citations[i] > h )
            {
                h++;
            }
            else
            {
                break;
            }
        }
        return h;
    }
};


int main()
{
    vector<int> citations{11,15};
    Solution s;
    cout << s.hIndex(citations) << '\n';
    return 0;
}
