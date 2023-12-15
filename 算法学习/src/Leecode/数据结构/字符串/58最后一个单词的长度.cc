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
    int lengthOfLastWord(string s) {

        int re{0};

        int i = s.size();
        for (; i > 0; i--)
        {
            if((s[i]>=97 && s[i]<=122) ||(s[i]>=65 && s[i]<=90) )
            {
                break;
            }
        }
        if(i==0)
        {
            return 1;
        }


        for (; i >= 0;i--)
        {

            if (!((s[i]>=97 && s[i]<=122)|| (s[i]>=65 && s[i]<=90) ) )
            {
                break;
            }
            re++;
        }
        return re;
    }
};


int main()
{
    string s{"qWnqNICa   ADGZNrBw  DdxMEuhNuvTJaETF   KhKKfVFX"};
    Solution ss;
    cout << ss.lengthOfLastWord(s) << '\n';
    return 0;
}
