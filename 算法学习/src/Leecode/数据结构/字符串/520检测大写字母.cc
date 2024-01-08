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
    bool detectCapitalUse(string word) {
        int capitals = 0;
        int first = 0;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if(i==0 && isCapital(word[i])){
                first++;
                capitals++;
            }
            else if(isCapital(word[i])){
                capitals++;
            }
        }
        if(capitals==n || (first==1 && capitals==1) ||capitals==0 ){
            return true;
        }
        return false;
    }
    bool isCapital(char c){
        if(c>='A' && c<='Z'){
            return true;
        }
        return false;
    }
};


int main()
{
    string word{"USA"};
    Solution s;
    cout << s.detectCapitalUse(word) << '\n';
    return 0;
}
