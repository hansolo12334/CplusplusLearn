#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>


class Solution
{
public:
    //左旋转字符串
    // 先反转前n个字符，后反转n到末端的字符，最后整体反转一次
    void leftRotateString(std::string &str,int n)
    {
        int s_size = str.length();
        reverseString(str, 0, n - 1);
        reverseString(str, n, s_size - 1);
        reverseString(str, 0, s_size - 1);
    }

    void reverseString(std::string &str,int phead,int ptail)
    {
        while(phead<ptail){
            std::swap(str[phead], str[ptail]);
            phead++;
            ptail--;
        }
    }
};



int main()
{
    std::string str{"abcdefg"};
    Solution ss;
    int n{2};
    ss.leftRotateString(str, n);
    std::cout <<str << '\n';
    return 0;
}
