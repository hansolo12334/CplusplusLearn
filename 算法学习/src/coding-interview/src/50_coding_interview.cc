#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

#include<unordered_map>

//第一个只出现一次的字符

// 用 哈希表
class Solution
{
public:
    char firstUniqChar(std::string &str)
    {
        std::unordered_map<char, int> map;
        std::vector<char> lst;
        for (auto c : str)
        {
            map[c]++;
            if(map[c]==1){
                lst.push_back(c);
            }
        }
        for(auto c: lst)
        {
            if(map[c]==1){
                return c;
            }
        }
        return ' ';
    }
};


int main()
{
    std::string s = "abaccdeff";
    Solution ss;
    std::cout << ss.firstUniqChar(s) << '\n';
    return 0;
}
