#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;


class Solution {
public:
    string toLowerCase(string s) {

        for (int i = 0; i < s.size();i++)
        {
            if( (s[i]>=65 && s[i]<=90))
            {
                s[i] += 32;
            }
        }
        return s;
    }
};



int main()
{
    string s{"Hello"};
    Solution ss;
    cout << ss.toLowerCase(s) << '\n';
    return 0;
}
