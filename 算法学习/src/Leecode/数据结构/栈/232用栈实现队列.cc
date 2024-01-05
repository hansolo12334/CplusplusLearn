#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <unordered_set>


using namespace std;


class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        // if(stk1.empty()&&stk2.empty()){
        //     stk1.push(x);
        //     m_size++;
        // }
        stk1.push(x);
        m_size++;
    }

    int pop() {
        int pop_item = 0;

        if(stk2.empty()){
            switch2stk(stk1, stk2);
        }
        pop_item = stk2.top();
        stk2.pop();
        m_size--;
        return pop_item;
    }

    int peek() {
        int peek_item = 0;
        if(stk2.empty()){
            switch2stk(stk1, stk2);
        }
        peek_item = stk2.top();
        return peek_item;
    }

    bool empty() {
        return m_size == 0;
    }


private:
    stack<int> stk1;
    stack<int> stk2;
    int m_size = 0;

    void switch2stk(stack<int> &stk1,stack<int> &stk2)
    {
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
    }

};


int main()
{
    vector<string> operators{"MyQueue", "push", "push", "peek", "pop", "empty"};
    vector<int> nums{{}, {1}, {2}, {}, {}, {}};
    MyQueue mq;
    for (int i = 1; i < operators.size();i++){
        if(operators[i]=="push"){
            cout << "push\n";
            mq.push(nums[i]);
        }
        if(operators[i]=="peek"){
            cout <<"peek "<< mq.peek() << '\n';
        }
        if(operators[i]=="pop"){
            cout <<"pop "<< mq.pop() << '\n';
        }
        if(operators[i]=="empty"){
            cout <<"empty "<< mq.empty() << '\n';
        }

    }
    return 0;
}
