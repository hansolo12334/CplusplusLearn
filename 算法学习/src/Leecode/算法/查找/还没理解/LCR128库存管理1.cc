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
    int stockManagement(vector<int>& stock) {
        if(stock.size()==1)
        {
            return stock[0];
        }
        int i = 0;
        int j = stock.size() - 1;
        while(i<j)
        {
            int mid = (j +i) / 2;
            if(stock[mid]<stock[j])
            {
                j=mid;
            }
            else if(stock[mid]>stock[j])
            {
                i = mid + 1;
            }
            else
            {
                j--;
            }
        }
        return stock[i];
    }
};


int main()
{
    vector<int> stock{4, 5, 8, 3, 4};
    Solution ss;
    cout << ss.stockManagement(stock) << '\n';
    return 0;
}
