#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

#include <deque>
#include <queue>


using namespace std;

 struct ListNode {
      int val;
      ListNode *next;


      ListNode()
        : val(0)
        , next(nullptr)
        {}
      ListNode(int x)
        : val(x)
        , next(nullptr)
        {}
      ListNode(int x, ListNode *next)
        : val(x)
        , next(next)
        {}
  };

class Solution {
public:

    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode *fast = head->next;
        ListNode *dummy = new ListNode{0,fast};

        while (fast != nullptr)
        {
            ListNode *fastNext = fast->next;
            if(fast->next==nullptr || fast->next->next==nullptr)
            {
                if(fast->next==nullptr)
                {
                    fast->next = head;
                    head->next = nullptr;
                }
                else if(fast->next->next==nullptr)
                {
                    ListNode *fastNext = fast->next;
                    fast->next = head;
                    head->next = fastNext;
                }

                break;
            }
            else{
                head->next = fast->next->next;
                fast->next = head;

                fast = head->next;
                head=fastNext;
            }
        }
        return dummy->next;
    }

//解法二 递归
    ListNode* swapPairs1(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }

        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};


int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2 = new ListNode{2};
    ListNode *l3 = new ListNode{3};
    ListNode *l4 = new ListNode{4};
    ListNode *l5 = new ListNode{5};
    ListNode *l6 = new ListNode{6};


    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    // l5->next = l6;

    Solution s;
    ListNode *re = s.swapPairs1(l1);
    while(re)
    {
        cout << re->val << ' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
