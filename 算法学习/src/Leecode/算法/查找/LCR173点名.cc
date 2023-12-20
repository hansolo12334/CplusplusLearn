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
    int takeAttendance(vector<int>& records) {
        if(records.size()==1 && records[0]==0)
        {
            return 1;
        }
        for (int i = 0; i < records.size();i++)
        {
            if(i!=records[i])
            {
                return i;
            }
        }
        return records.size();
    }
//方法二 二分法
    int takeAttendance1(vector<int>& records) {
        int left = 0;
        int right = records.size() - 1;
        while(left<=right)
        {
            int mid = (left + right) / 2;
            if(records[mid]==mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};


int main()
{
    vector<int> records{0, 1, 2, 3, 5};
    Solution ss;
    cout << ss.takeAttendance1(records) << '\n';
    return 0;
}
