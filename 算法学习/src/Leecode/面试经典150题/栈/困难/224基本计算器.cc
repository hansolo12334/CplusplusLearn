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
    int calculate(string s) {
        //存放数字
        stack<int> numbers{};
        numbers.push(0);

        replace(s);//去掉所有空格
        //存放操作符
        stack<char> manus{};

        string number{};

        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c=='('){
                manus.push(c);
            }
            else if(c==')'){
                //计算到最近的一个左括号为止
                while(!manus.empty()){
                    char manu = manus.top();
                    if(manu!='('){
                        cal(numbers, manus);
                    }
                    else{
                        manus.pop();
                        break;
                    }
                }
            }
            else{
                //如果是数字
                if(isdigit(c)){
                    int cur_num = 0;
                    int j = i;
                    //数字字符拼接 将第i位置后面的连续字符取出 放入numbers
                    while(j<s.size() && isdigit(s[j])){
                        cur_num = cur_num * 10 + (s[j++] - '0');
                    }
                    numbers.push(cur_num);
                    // i 跳到 j-1位置
                    i = j - 1;
                }
                //如果 c是 操作符 + -
                else{
                    //如果操作符左边时左括号
                    if(i>0 && (s[i-1]=='(' || s[i-1]=='+' || s[i-1]=='-')){
                        numbers.push(0);
                    }
                    //当有新的操作符入栈时，先把栈内的操作符使用了
                    while (!manus.empty() && manus.top()!='('){
                        cal(numbers, manus);
                    }
                    //加入新的操作符
                    manus.push(c);
                }
            }
        }
        //最后在把剩余的操作符使用掉
        while(!manus.empty()){
            cal(numbers, manus);
        }
        return numbers.top();
    }


    void replace(string &s){
        int pos = s.find(" ");
        while(pos!=-1){
            s.replace(pos, 1, "");
            pos = s.find(" ");
        }
    }
    void cal(stack<int> &nums,stack<char> &manus){
        if(nums.size()<2|| manus.empty()){
            return;
        }
        int y = nums.top();
        nums.pop();
        int x = nums.top();
        nums.pop();
        char manu = manus.top();
        manus.pop();
        nums.push(manu == '+' ? x + y : x - y);
    }
};


int main()
{
    string s{"(1+(4+5+2)-3)+(6+8)"};
    Solution ss;
    cout << ss.calculate(s) << '\n';
    return 0;
}
