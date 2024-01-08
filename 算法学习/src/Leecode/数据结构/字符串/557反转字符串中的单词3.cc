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
    string reverseWords(string s) {
        int n = s.length();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while(j+1 <n && s[j+1]!=' '){
                j++;
            }

            reverseBe(s, i, j);
            j++;
            while (s[j] == ' ')
            {
                j++;
            }

            i = j - 1;
        }
        return s;
    }

    void reverseBe(string &s, int be,int end){
        while(be<end){
            swap(s[be], s[end]);
            be++;
            end--;
        }
    }
};


int main()
{
    string s{"Let's take LeetCode contest"};
    Solution ss;
    cout << ss.reverseWords(s) << '\n';
    return 0;
}
