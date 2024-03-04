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
    // int countBinarySubstrings(string s) {
    //     int re = 0;
    //     int lianxZero = 0;
    //     bool lianZero = false;

    //     int lianxOne = 0;
    //     bool lianOne = false;

    //     int n = s.length();
    //     for (int l = 0; l < n;l++)
    //     {
    //         lianOne = 0;
    //         lianZero = 0;
    //         lianxOne = 0;
    //         lianxZero = 0;

    //         int crossTime = 0;

    //         for (int i = l; i < n; i++)
    //         {
    //             if (s[i] == '1')
    //             {
    //                 if (lianOne == false)
    //                 {
    //                     lianOne = true;
    //                 }
    //                 lianxOne++;
    //             }
    //             else{
    //             if(lianOne){
    //                 crossTime++;
    //                 lianOne = false;
    //             }
    //         }


    //         if(s[i]=='0'){
    //             if(lianZero==false){
    //                 lianZero = true;
    //             }
    //             lianxZero++;
    //         }
    //         else{
    //             if(lianZero){
    //                 crossTime++;
    //                 lianZero = false;
    //             }
    //         }


    //         if(lianxOne==lianxZero && (lianZero|lianOne==true)){
    //             re += lianxOne;
    //             l = (i - l) / 2 + l;
    //             break;
    //         }
    //         if(crossTime>=2)
    //         {
    //             break;
    //         }
    //         }
    //     }

    //     return re;
    // }

    int countBinarySubstrings(string s) {
        int re = 0;

        unordered_map<char, int> map;

        int n = s.length();

        vector<int> itemsSize{};
        // vector<char> items{};
        for (int i = 0; i < n; i++)
        {
            map[s[i]]++;
            // if(i==0 || map[s[i]]==1)
            // {
            //     items.push_back(s[i]);
            // }
            if(i!=0&&s[i - 1]!=s[i]){
                itemsSize.push_back(map[s[i - 1]]);
                map[s[i - 1]] = 0;
            }
        }
        itemsSize.push_back(map[s[n - 1]]);

        for (int i = 0; i < itemsSize.size();i++)
        {
            if(i>0){
                re += min(itemsSize[i], itemsSize[i - 1]);
            }
        }
        return re;
    }
};

int main()
{
    string s{"00110011"};
    Solution ss;
    cout << ss.countBinarySubstrings(s) << '\n';
    return 0;
}
