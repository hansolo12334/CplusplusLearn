#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;


//整数0-9 的ascii 范围 48-57
//负号的 ascii  55 ＋: 53
//空格 ascii 32




class Solution {
public:
    int myAtoi(string s) {

        long long re{0};
        auto sp{s.begin()};

        long long spots{1};

        vector<int> items;
        bool LetterLeftInt{0};
        bool IntLeftLetter{0};

        bool negetive{0};


        while (sp < s.end())
        {
            if( isInt(*sp))
            {
                if(!LetterLeftInt ) // 如果此时数字左侧没字母 则 字母左侧有数字为 真
                {
                    IntLeftLetter = 1;
                    items.push_back(static_cast<int>(*sp) - 48);
                }
            }
            else if( *sp=='-')
            {
                if(!isInt(*(sp+1)))
                {
                    if(sp!=s.begin())
                    {
                        if(isInt(*(sp-1)))
                        {
                            break;
                        }

                    }
                    return 0;
                }

                  if(sp!=s.begin())
                {
                    if(isInt(*(sp-1)))
                    {
                        break;
                    }

                }
                negetive = true;

            }
            else if( *sp=='+')
            {
                if(sp!=s.end()-1)
                {
                    if(!isInt(*(sp+1)))
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }

                if(isInt(*(sp-1)))
                {

                    break;
                }
                negetive = false;

            }
            else if(*sp==' ')
            {
                 if(sp!=s.begin())
                {
                    if(isInt(*(sp-1)))
                    {
                        break;
                    }
                }
            }
            else if(!IntLeftLetter) //当前字符 为 为除了空格 数字 以外的字符 判定数字左侧有字母
            {
                LetterLeftInt = 1;
            }
            else if(IntLeftLetter)
            {
                break;
            }
            sp++;
        }


        if(items.empty())
        {
            return 0;
        }

         auto ppf{items.begin()};
        while (*ppf==0  && ppf!=items.end()-1)
        {
            ppf++;
        }
        auto ppe{items.end()-1};
        int sumSpot = 0;
        while (ppe >= ppf)
        {
            re += *ppe * spots;

            if(sumSpot>9 && ((spots > ((long long)INT_MAX))||(re> ((long long)INT_MAX))))
            {
                re=(long long)INT_MAX+1;
                break;
            }
            spots *= 10;
            sumSpot++;
            if(ppe==ppf)
            {
                break;
            }
            ppe--;
        }
        if(negetive)
        {
            re = -re;
        }

        if(re< (long long)INT_MIN)
        {
            return (long long)INT_MIN;
        }
        if(re > (long long)INT_MAX )
        {
            return (long long)INT_MAX;
        }
        return re;
    }


    bool isInt(char sp)
    {
        if( ( static_cast<int>(sp)>= 48) && (static_cast<int>(sp)<=57))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string input{"21474836++"};
    Solution s;
    cout << s.myAtoi(input) << '\n';

    return 0;
}
