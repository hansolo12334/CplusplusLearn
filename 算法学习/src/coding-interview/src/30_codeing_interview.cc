#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

template<typename T>
class MyStack
{

private:
    std::stack<T> stack1{};
    std::stack<T> stack2{};

public:
    void push(T data)
    {
        stack1.push(data);
        if(stack2.empty() || stack2.top()>data){
            stack2.push(data);
        }
        else if(!stack2.empty() && stack2.top()<data){
            stack2.push(stack2.top());
            //始终保持两个栈大小相同，
            //且stack2的栈顶始终是stack1的最小值
        }
    }

    void pop()
    {
        stack1.pop();
        stack2.pop();
    }

    T top()
    {
        return stack1.top();
    }

    T getMin()
    {
        return stack2.top();
    }
};


int main()
{
    MyStack<int> minStack{};
    minStack.push(-1);
    minStack.push(3);
    minStack.push(-4);
    std::cout << minStack.getMin() << '\n';
    minStack.pop();
    std::cout << minStack.top() << '\n';
    std::cout << minStack.getMin() << '\n';

    return 0;
}
