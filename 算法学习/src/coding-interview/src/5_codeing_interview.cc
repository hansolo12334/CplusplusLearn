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
};


int main()
{
    std::string str{"We are happy."};
    Solution ss;
    std::cout << ss.replaceSpaces(str) << '\n';
    return 0;
}
