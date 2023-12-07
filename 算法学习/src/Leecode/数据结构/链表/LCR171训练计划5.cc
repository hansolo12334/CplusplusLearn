#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

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
    ListNode(int x,ListNode*next)
        : val(x)
        , next(next)
        {}
  };


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        while(headA)
        {
            stackA.push(headA->val);
            headA = headA->next;
        }
        while(headB)
        {
            stackB.push(headB->val);
            headB = headB->next;
        }


        ListNode *re=nullptr;
        while (!stackA.empty() && !stackB.empty())
        {
            if(stackA.top()==stackB.top())
            {
                re = new ListNode{};
                re->val = stackA.top();
            }
            stackA.pop();
            stackB.pop();
        }
        return re;
    }
    //双指针
      ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while (A != B) {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }



private :
    stack<int> stackA;
    stack<int> stackB;


};





int main()
{
    ListNode *l1 = new ListNode{4};
    ListNode *l2= new ListNode{1};
    ListNode *l3 = new ListNode{8};
    ListNode *l4 = new ListNode{4};
    ListNode *l5 = new ListNode{5};

    ListNode *l6 = new ListNode{5};
    ListNode *l7 = new ListNode{0};
    ListNode *l8 = new ListNode{1};
    ListNode *l9 = new ListNode{8};
    ListNode *l10 = new ListNode{4};
    ListNode *l11 = new ListNode{5};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;



    l6->next = l7;
    l7->next = l8;
    l8->next = l9;
    l9->next = l10;
    l10->next = l11;


    Solution s;
    ListNode *re=s.getIntersectionNode(l1,l6);

    while(re!=nullptr)
    {
        cout << re->val<<' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
