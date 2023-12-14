#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>
#include<queue>


using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        queue<char> que{};
        size_t needle_p{0};
        size_t haystack_p{0};
        size_t start{0};
        while (haystack_p+start <= (haystack.size() - 1))
        {
            if(haystack[haystack_p+start]==needle[needle_p])
            {
                needle_p++;
                start++;
            }
            else
            {
                start = 0;
                needle_p = 0;
                haystack_p++;
            }
            if(needle_p>=needle.size())
            {
                return haystack_p+start-needle.size();
            }
        }
        return -1;
    }
};

int main()
{
    string haystack{"mississippi"};
    string needle{"issip"};
    Solution ss;
    cout << ss.strStr(haystack, needle) << '\n';
    return 0;
}
