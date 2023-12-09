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


class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        myQueue.push_back(value);
    }

    int deleteHead() {
        // for(int q:myQueue)
        // {
        //     cout << q << ' ';
        // }
        // cout << '\n';
        if (!initIter && !myQueue.empty())
        {
            initIter = true;
            phead = myQueue.begin();
        }
        if (phead>= (myQueue.end()))
        {
            return -1;
        }
        int headValue{*phead};
        // vector<int> newQueue{ (phead+1), myQueue.end()};
        // myQueue = newQueue;
        if( (phead)< (myQueue.end()))
        {
            phead++;
        }



        return headValue;
    }

private:
    vector<int> myQueue;
    bool initIter{0};
    vector<int>::iterator phead{};
};
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */


int main()
{
    CQueue *obj = new CQueue();
    vector<string> opreates{"CQueue","deleteHead","appendTail","deleteHead","appendTail","appendTail","deleteHead","deleteHead","deleteHead","appendTail","deleteHead","appendTail","appendTail","appendTail","appendTail","appendTail","appendTail","deleteHead","deleteHead","deleteHead","deleteHead"};
    for (int i = 1; i < opreates.size();i++)
    {
        if(opreates[i]=="deleteHead")
        {
            std::cout << obj->deleteHead() << '\n';
        }
        if(opreates[i]=="appendTail")
        {
            obj->appendTail(1);
        }
    }
    // obj->appendTail(1);
    // obj->appendTail(2);
    // std::cout << obj->deleteHead() << '\n';
    // std::cout << obj->deleteHead() << '\n';
    return 0;
}
