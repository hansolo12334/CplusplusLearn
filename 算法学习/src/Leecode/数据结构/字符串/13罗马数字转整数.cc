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
        for (int i = s.size() - 1; i >= 0; --i)
        {
            string temp{s[i]};
            cout << "for " << i << '\n';
            string copy{};

            int j = i - 1;
            //while (map.count(temp)!=0 && j>=0)
            for (; j >= 0;j--)
            {
                copy = temp;
                temp = string{s[j]} + temp;

                if(map.count(temp)==0)
                {
                    temp = copy;
                    i = j+1;
                    cout << "temp: " << temp << ' ' << map.count(temp) << '\n';
                    break;
                }
                cout << "temp: " << temp << ' ' << map.count(temp) << '\n';
            }
            cout << temp <<' '<< map[temp]<< '\n';
            re += map[temp];
            if(j==-1)
            {
                return re;
            }
        }

        return re;
    }
    int romanToInt1(string s) {
        //通常情况下，罗马数字中小的数字在大的数字的右边
        //如果小的数字在大的左边 则减去小的 否则逐个单字符累加
        unordered_map<char, int> map{{'I', 1},
                                       {'V', 5},
                                       {'X', 10},
                                       {'L', 50},
                                       {'C', 100},
                                       {'D', 500},
                                       {'M', 1000},
                                      };
        int re{0};
        for (int i = 0; i < s.size(); i++)
        {
            if(i+1<s.size() && map[s[i]]<map[s[i+1]])
            {
                re -= map[s[i]];
            }
            else
            {
                re += map[s[i]];
            }
        }
        return re;
    }
};


int main()
{
    string s{"III"};
    Solution ss;
    cout << ss.romanToInt1(s) << '\n';
}
