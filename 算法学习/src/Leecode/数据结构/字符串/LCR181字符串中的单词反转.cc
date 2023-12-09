#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>

using namespace std;


class Solution {
public:
    string reverseMessage(string message) {
        if(message.empty())
        {
            return {};
        }
        if(message[0]!=' ')
        {
            message = ' ' + message;
        }

        string re{};
        auto pleft{message.end()-1};
        auto pright{message.end()-1};



        while (pleft >message.begin())
        {

            while(*pleft==' '&&(pleft>message.begin()))
            {
                pleft--;
            }
            if(pleft<=message.begin())
            {
                break;
            }

            pright = pleft; //左右指针对齐 到一个单词右侧

            while(*pleft!=' ' && (pleft>message.begin()) ) //左指针移动到这个单词的左侧
            {
                pleft--;
            }
            string temp{pleft+1, pright+1};
            re += temp;
            re += ' ';
            pright = pleft;


        }


        return re.empty() ? string{} : string{re.begin(), re.end() - 1};
    }
};



int main()
{
    string message{"  hello world!  "};
    Solution s;
    cout << s.reverseMessage(message) << "1\n";
    return 0;
}
