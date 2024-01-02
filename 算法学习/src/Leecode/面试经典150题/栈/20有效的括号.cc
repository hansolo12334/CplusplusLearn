#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>
#include<map>
#include<unordered_set>


using namespace std;


class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n==1 || n%2!=0 || s[n - 1] == '{' || s[n - 1] == '[' || s[n - 1] == '('){
            return false;
        }


        stack<char> stk;
        // stack<char> stk_r;

        for(char ele : s)
        {
            stk.push(ele);
        }

        stack<char> tempstk;
        tempstk.push(stk.top());
        //如果遇到右括号 则必须先找到对应的左括号 如果在匹配中遇到新的右括号类型 则设该类型为当前匹配的右括号
        //栈顶为右括号 ) ] }
        char currentType = stk.top();
        stk.pop();

        unordered_map<char, char> maps{{']', '['},
                                       {')', '('},
                                       {'}', '{'}};

        int tempT = 2;
        while (!tempstk.empty() )
        {
            //情况一 匹配到相对的左括号
            if(maps[tempstk.top()]==stk.top())
            {
                tempstk.pop();
                stk.pop();
                tempT = 2;
            }
            //情况二 遇到了新的右括号
            if(!stk.empty()&&  (stk.top()==')' || stk.top()=='}'|| stk.top()==']'))
            {
                tempstk.push(stk.top());
                stk.pop();
                tempT = 2;
            }
            if(!stk.empty() && tempstk.empty()&&  (stk.top()=='[' || stk.top()=='{'|| stk.top()=='(') ||(stk.empty() &&!tempstk.empty()))
            {
                return false;
            }
            tempT--;
            if(tempT==0){
                return false;
            }
        }


        return true;
    }

    //方法二 官方解法
    bool isValid1(string s) {
        int n = s.size();
        if(n%2!=0)
        {
            return false;
        }
        unordered_map <char,char> pairs{{']', '['},
                                       {')', '('},
                                       {'}', '{'}};
        stack<char> stk;
        for(char ch:s)
        {
            if(pairs.count(ch))
            {
                if(stk.empty() || stk.top()!=pairs[ch]){
                    return false;
                }
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};



int main()
{
    string s{"{}{}{}{}()()"};
    Solution ss;
    cout << ss.isValid1(s) << '\n';
    return 0;
}
