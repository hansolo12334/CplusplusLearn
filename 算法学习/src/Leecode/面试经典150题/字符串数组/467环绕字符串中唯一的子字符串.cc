#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>
#include<numeric>


using namespace std;

class Solution {
public:
    // int findSubstringInWraproundString(string s) {
    //     int re = 0;
    //     int n = s.length();

    //     if(n==1){
    //         return 1;
    //     }
    //     int count = 0;
    //     unordered_map<int, int> map;

    //     vector<int> lians{};
    //     int lianx = 1;

    //     for (int i = 0; i < n; i++)
    //     {
    //         map[s[i]]++;
    //         if(map[s[i]]==1){
    //             count++;
    //         }
    //         // else if(map[s[i]]>=2){
    //         //     continue;
    //         // }
    //         if (i > 0)
    //         {
    //             if( (s[i-1]=='z'&&s[i]=='a') || (s[i-1]+1==s[i]))
    //             {
    //                 // re++;
    //                 lianx++;
    //             }
    //             else{
    //                 // if(lianx>=2){
    //                 //     re += ((lianx + 1 - 2) + 1) * (lianx + 1 - 2) / 2;
    //                 //     cout<<((lianx + 1 - 2) + 1) * (lianx + 1 - 2) / 2<<'\n';
    //                 // }
    //                 lians.push_back(lianx);
    //                 lianx = 1;
    //             }
    //         }
    //     }
    //     if(lianx>=1){
    //         lians.push_back(lianx);
    //     }
    //     for (int i = 0; i < lians.size();i++){
    //         cout<<lians[i]<<' ';
    //         re += (lians[i] + 1) * lians[i] / 2;
    //     }
    //     cout << '\n';

    //     return re;
    // }
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26);
        int k = 0;
        for (int i = 0; i < s.length();i++){
            if(i>0){
                if((s[i]-s[i-1]+26)%26==1){
                    k++;
                }
                else{
                    k = 1;
                }
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], k);
        }

        int re = accumulate(dp.begin(), dp.end(), 0);

        return re;
    }
};

int main()
{
    string s = "abc";
    Solution ss;
    cout << ss.findSubstringInWraproundString(s) << '\n';
    return 0;
}
