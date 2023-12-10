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

        if(myQueue.empty())
        {
            return -1;
        }
        if (!initIter)
        {
            initIter = true;
            phead = 0;
        }

        int headValue{};

        if((phead)> (myQueue.size()-1))
        {
            return -1;
        }

        headValue = myQueue[phead];
        phead++;

        return headValue;

    }

private:
    vector<int> myQueue;
    bool initIter{0};
    int phead{};
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
    vector<int> inputs{{},  {},  {12}, {},  {10}, {9}, {}, {}, {}, {20}, {},
                       {1}, {8}, {20}, {1}, {11}, {2}, {}, {}, {}, {}};

    for (int i = 1; i < opreates.size(); i++)
    {
        if(opreates[i]=="deleteHead")
        {
            std::cout << "delete ";
            std::cout << obj->deleteHead() << '\n';
        }
        if(opreates[i]=="appendTail")
        {
            std::cout << "add " << inputs[i] << '\n';
            obj->appendTail(inputs[i]);
        }
    }
    // obj->appendTail(1);
    // obj->appendTail(2);
    // std::cout << obj->deleteHead() << '\n';
    // std::cout << obj->deleteHead() << '\n';
    return 0;
}
