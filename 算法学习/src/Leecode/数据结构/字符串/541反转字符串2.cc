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
    string reverseStr(string s, int k) {
        if(k==1){
            return s;
        }
        int n = s.length();

        for (int i = 0; i < s.length();)
        {
            if( (i+2*k)<n   ){
                reverseBt(s, i, i + k - 1);
                i = i + 2 * k;
            }
            else if( (i+k)<n ){
                reverseBt(s, i, i + k - 1);
                break;
            }
            else if(n-i-1<k){
                reverseBt(s, i, n - 1);
                break;
            }
        }
        return s;
    }

    void reverseBt(string &s,int be,int end){
        while(be<end){
            swap(s[be], s[end]);
            be++;
            end--;
        }
    }
};


int main()
{
    string s{"abcdefg"};
    int k = 3;
    Solution ss;
    cout << ss.reverseStr(s, k) << '\n';
    return 0;
}
