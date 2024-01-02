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
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers{};
        for (int i = 0; i < tokens.size();i++){
            if( tokens[i] !="+" && tokens[i]!="-" &&  tokens[i]!="/" && tokens[i]!="*"){
                numbers.push(stoi(tokens[i]));
            }
            else{
                int y = numbers.top();
                numbers.pop();
                int x = numbers.top();
                numbers.pop();
                if (tokens[i] == "+")
                {
                    numbers.push(x + y);
                }
                if (tokens[i] == "-")
                {
                    numbers.push(x- y);
                }
                if (tokens[i] == "*")
                {
                    numbers.push(x * y);
                }
                if (tokens[i] == "/")
                {
                    numbers.push(x / y);
                }
            }
        }
        return numbers.top();
    }
};


int main()
{
    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    cout << s.evalRPN(tokens) << '\n';
    return 0;
}
