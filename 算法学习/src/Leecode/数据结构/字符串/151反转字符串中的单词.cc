#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;


class Solution
{
public:
    string reverseWords(string s)
    {
        string re;
        int j = s.length() - 1;
        while (s[j] == ' ')
        {
            j--;
        }
        int i = 0;
        while(s[i]==' '){
            i++;
        }
        string temp{};
        while (j >= i)
        {
            while ((j - 1) >= 0 && s[j - 1] != ' ')
            {
                temp += s[j];
                j--;
            }
            temp += s[j];


            j--;
            reverse(temp.begin(), temp.end());


            while ((j - 1) >= 0 && s[j] == ' ')
            {
                j--;
            }
            if (j >=i)
            {
                temp = temp+ ' ' ;
            }
            re = re + temp;
            temp.clear();
            // j--;
        }
        return re;
    }
};

int main()
{
    string s{"  hello world  "};
    Solution ss;
    cout << ss.reverseWords(s) << "2\n";
    return 0;
}
