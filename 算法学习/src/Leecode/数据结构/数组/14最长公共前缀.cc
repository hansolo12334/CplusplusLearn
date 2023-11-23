//最长公共前缀

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size()==1)
        {
            return strs[0];
        }

        std::string re;

        std::vector<std::string::iterator> vc;
        for (size_t i = 0; i < strs.size(); i++)
        {
            if(strs[i].size()==0){
                return re;
            }

            vc.push_back(strs[i].begin());
        }
        int f{1};
        while (f)
        {
            int flag{0};
            for (size_t i = 1; i < vc.size(); i++)
            {
                if(*vc[0]==*vc[i])
                {
                    flag++;
                }
                else
                {
                    return re;
                }
            }
            if (flag==vc.size()-1)
            {
                re.push_back(*vc[0]);

                vc[0]++;
                if(vc[0]>=strs[0].end())
                {
                    f=0;
                }
                for (size_t i = 1; i < vc.size(); i++)
                {
                    vc[i]++;
                    if(vc[i]>=strs[i].end())
                    {
                        f=0;
                    }
                }
            }
            else{
                break;
            }

        }

        return re;
    }
};


int main()
{
    std::vector<std::string> strs{"a"};

    Solution s;

    std::cout << s.longestCommonPrefix(strs) << '\n';
    return 0;
}
