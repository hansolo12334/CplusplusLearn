#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>



using namespace std;


class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        int absent = 0;
        int late = 0;
        int present = 0;
        int lianxu = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='A')
            {
                absent++;
            }
            if(s[i]=='L')
            {
                if(late==0)
                {
                    lianxu = 1;
                }
                late++;
                if(late>=3)
                {
                    return false;
                }
            }
            else
            {
                if(lianxu)
                {
                    lianxu = 0;
                    late = 0;
                }
            }
        }
        return absent >= 2 ? false : true;
    }
};


int main()
{
    string s{"PPALLL"};
    Solution ss;
    cout<<ss.checkRecord(s)<<'\n';
    return 0;
}
