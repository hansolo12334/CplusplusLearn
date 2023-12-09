#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;

//方法一 双指针
class Solution {
public:

    void reverseString(vector<char>& s) {
        if(s.empty())
        {
            return;
        }
        int fp{0};
        auto ep{s.size()-1};
        while(fp<ep)
        {
            swap(s[fp], s[ep]);
            fp++;
            ep--;
        }
    }
};


int main()
{
    vector<char> ss{'h', 'e', 'l', 'l', 'o'};
    Solution s;
    s.reverseString(ss);
    for (char sss : ss)
    {
        std::cout << sss << ' ';
    }
    std::cout << '\n';
    return 0;
}
