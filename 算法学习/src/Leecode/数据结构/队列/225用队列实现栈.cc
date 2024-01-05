#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include<queue>

#include <limits.h>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <unordered_set>


using namespace std;


class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int popItem = 0;
        if (que1.empty())
        {
            popQue2to1();
            popItem = que2.front();
            que2.pop();
        }
        else
        {
            popQue1to2();
            popItem = que1.front();
            que1.pop();
        }
        return popItem;
    }

    int top() {
        int topItem = 0;
        if (que1.empty())
        {
            popQue2to1();
            topItem = que2.front();
            que1.push(topItem);
            que2.pop();
        }
        else
        {
            popQue1to2();
            topItem = que1.front();
            que2.push(topItem);
            que1.pop();
        }
        return topItem;

    }
    bool empty() {
        return que1.empty() && que2.empty();
    }

private:
    queue<int> que1;
    queue<int> que2;

    void popQue2to1()
    {
        while(que2.size()>1){
            que1.push(que2.front());
            que2.pop();
        }
    }
    void popQue1to2()
    {
        while(que1.size()>1){
            que2.push(que1.front());
            que1.pop();
        }
    }
};


int main()
{
    vector<string> operators{"MyStack", "push", "push", "top", "pop", "empty"};
    vector<int> nums{{}, {1}, {2}, {}, {}, {}};
    MyStack mq;
    for (int i = 1; i < operators.size();i++){
        if(operators[i]=="push"){
            cout << "push\n";
            mq.push(nums[i]);
        }
        if(operators[i]=="top"){
            cout <<"top "<< mq.top() << '\n';
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
