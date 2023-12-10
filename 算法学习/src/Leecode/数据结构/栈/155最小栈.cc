#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

#include<queue>

using namespace std;


class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        // if(!initStack)
        // {
        //     initStack = true;
        //     // minValue = val;
        //     topPointer = 0;
        //     myStack.push_back(val);
        //     return;
        // }

        // if (val<minValue)
        // {
        //     minValue = val;
        // }
        myStack.push_back(val);
        //topPointer++;
    }

    void pop() {
        // topPointer--;
        vector<int> temp{myStack.begin(), myStack.end() - 1};
        myStack = temp;
    }

    int top() {
        return *(myStack.end()-1);
    }

    int getMin() {
        return  *min_element(myStack.begin(),myStack.end());
    }

private:
    vector<int> myStack{};
    // int topPointer{};
    // int minValue{};
    // bool initStack{false};
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    vector<string> operators{"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<int> inputs{{},{-2},{0},{-3},{},{},{},{}};
    MinStack *obj = new MinStack();

    for (int i = 1; i < operators.size();i++)
    {
        if(operators[i]=="push")
        {
            obj->push(inputs[i]);
        }
        if(operators[i]=="pop")
        {
            obj->pop();
        }
        if(operators[i]=="getMin")
        {
            cout <<"getMin "<< obj->getMin() << '\n';
        }
        if(operators[i]=="top")
        {
            cout <<"top "<< obj->top() << '\n';
        }

    }
}
