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
    int romanToInt(string s) {
        //通常情况下，罗马数字中小的数字在大的数字的右边
        unordered_map<string, int> map{{"I", 1},
                                       {"V", 5},
                                       {"X", 10},
                                       {"L", 50},
                                       {"C", 100},
                                       {"D", 500},
                                       {"M", 1000},
                                       {"IV", 4},
                                       {"IX", 9},
                                       {"XL", 40},
                                       {"XC", 90},
                                       {"CD", 400},
                                       {"CM", 900}};
        int re{0};
        for (size_t i = s.size() - 1; i > 0; i--)
        {
            string temp{s[i]};
            cout << temp << '\n';
            string copy{};
            while (map.count(temp))
            {
                i--;
                copy = temp;
                temp = string{s[i]} + temp;

                //cout << "II" <<' '<< map.count("II") << '\n';
                //cout << temp <<' '<< map.count(temp)<< '\n';
            }
            i++;
            re += map[copy];
            cout << re << '\n';
        }

        return re;
    }
};


int main()
{
    string s{"III"};
    Solution ss;
    cout << ss.romanToInt(s) << '\n';
}
