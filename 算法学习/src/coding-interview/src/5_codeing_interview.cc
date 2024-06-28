#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>


class Solution
{
public:
    std::string replaceSpaces(std::string str)
    {
        std::string re{};
        for (int i = 0; i < str.length(); ++i)
        {
            if(str[i]==' ')
            {
                re += "%20";
            }
            else{
                re += str[i];
            }
        }
        return re;
    }
    std::string replaceSpaces1(std::string str)
    {
        int s_size = str.length();
        for (int i = 0; i < s_size;++i)
        {
            if(str[i]==' '){
                str += "  ";
            }
        }
        int phead = s_size-1;
        int  ptail = str.length()-1;
        for (; phead >= 0;--phead)
        {
            if (str[phead] == ' ')
                {
                    str[ptail] = '0';
                    ptail--;
                    str[ptail] = '2';
                    ptail--;
                    str[ptail] = '%';
                    ptail--;
                }
                else
                {
                    str[ptail] = str[phead];
                    ptail--;
                }
        }
        return str;
    }
};


int main()
{
    std::string str{"We are happy."};
    Solution ss;
    std::cout << ss.replaceSpaces1(str) << '\n';
    return 0;
}
