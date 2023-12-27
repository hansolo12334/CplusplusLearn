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
    bool isPalindrome(string s) {
        int j = s.length()-1;
        if(j==0)
        {
            return true;
        }
        int nums{0};
        int i = 0;

        while(i<j)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i] += 32;
            }
            if(s[j]>='A' && s[j]<='Z')
            {
                s[j] += 32;
            }

            //如果两边都是字符 就i++ j-- 否则返回false
            if( checkIntChar(s[i])  &&  checkIntChar(s[j]) )
            {
                if(s[i]!=s[j]){
                    return false;
                }
                i++;
                j--;
            }
            //如果一边不是字符 则这边向中间移动
            else if( checkIntChar(s[i]) && !checkIntChar(s[j]))
            {
                nums++;
                j--;
            }
            else if( !checkIntChar(s[i]) && checkIntChar(s[j]) )
            {
                nums++;
                i++;
            }
            else if ( !checkIntChar(s[i]) && !checkIntChar(s[j]) )
            {
                i++;
                j--;
            }


        }
        return true;
    }

    bool checkIntChar(char s)
    {
        if((s>='a' && s<='z') || (s>='0' && s<='9'))
        {
            return true;
        }
        return false;
    }

    //方法二 借助stl api   isalnum 判断字符是否为数字或字母 tolower  转换大小写
bool isPalindrome1(string s) {
        int j = s.length()-1;
        if(j==0)
        {
            return true;
        }
        int nums{0};
        int i = 0;

        while(i<j)
        {
            //如果两边都是字符 就i++ j-- 否则返回false
            if( isalnum(s[i])   &&  isalnum(s[j]) )
            {
                if(tolower(s[i])!=tolower(s[j])){
                    return false;
                }
                i++;
                j--;
            }
            //如果一边不是字符 则这边向中间移动
            else if( isalnum(s[i]) && !isalnum(s[j]))
            {
                nums++;
                j--;
            }
            else if( !isalnum(s[i]) && isalnum(s[j]) )
            {
                nums++;
                i++;
            }
            else if ( !isalnum(s[i]) && !isalnum(s[j]) )
            {
                i++;
                j--;
            }
        }
        return true;
    }
};


int main()
{
    string s{"A man, a plan, a canal: Panama"};
    Solution ss;
    cout << ss.isPalindrome1(s) << '\n';
    return 0;
}
