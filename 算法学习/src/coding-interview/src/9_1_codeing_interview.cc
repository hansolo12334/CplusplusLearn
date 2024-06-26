#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>



template<typename T>
class MyQueue
{
public:
    void push(T data)
    {
        stack1.push(data);
    }

    T pop()
    {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        T data{stack2.top()};
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return data;
    }

    T peek()
    {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        T data = stack2.top();
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return data;
    }

    bool empty()
    {
        return stack1.empty();
    }


private:
    std::stack<T> stack1{};
    std::stack<T> stack2{};
};

template<typename T>
class MyQueue1
{
private:
    std::stack<T> stack1{};
    std::stack<T> stack2{};

public:
    void push(T data)
    {
        stack1.push(data);
    }
    T pop()
    {
        T data = peek();
        stack2.pop();
        return data;
    }

    T peek()
    {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty()
    {
        if(stack1.empty()&&stack2.empty())
        {
            return true;
        }
        return false;
    }
};


int main()
{
    MyQueue1<int> queue{};
    queue.push(1);
    queue.push(2);
    std::cout << queue.peek() << '\n';
    std::cout << queue.pop() << '\n';
    std::cout << queue.empty() << '\n';
    return 0;
}
