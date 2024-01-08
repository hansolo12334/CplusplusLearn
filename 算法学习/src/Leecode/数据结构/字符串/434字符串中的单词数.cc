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
    int countSegments(string s) {
        int cnt = 0;
        int n = s.length();
        bool charac=false;
        for (int i = 0; i < n;i++){

            if( (i==0&&s[i]!=' ') || (i>0 &&s[i-1]==' '&&s[i]!=' ') ){
                cnt++;
            }

            }


        return cnt;
    }
};

int main()
{
    string s{"                "};
    Solution ss;
    cout << ss.countSegments(s) << '\n';
    return 0;
}
