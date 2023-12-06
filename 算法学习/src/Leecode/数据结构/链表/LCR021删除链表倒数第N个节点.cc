#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;



//  * Definition for singly-linked list.
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
//解法一 递归
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *bk = head;
        recur(bk, n);
        if (time==n)
        {
            head = head->next;
        }


        return head;
    }



//解法二 栈
    ListNode* removeNthFromEnd2(ListNode* head, int n)
    {
        ListNode *dummy = new ListNode{0, head};
        stack<ListNode *> stk;
        ListNode *cur = dummy;
        while(cur)
        {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n;i++)
        {
            stk.pop();  //栈顶弹出 是从后向前弹出 弹到倒数第n个节点
        }
        ListNode *prev = stk.top();
        prev->next = prev->next->next; //找到倒数第n+1个节点 让其next指向倒数第n-1个节点
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
//解法三 双指针
    ListNode* removeNthFromEnd3(ListNode* head, int n)
    {
        ListNode *dummy = new ListNode{0, head};
        ListNode *first = head;
        ListNode *second = dummy;
        //first 比 second超前n个节点，因此当first到达终点时，second刚好在倒数第n个节点
        for (int i = 0; i < n;i++)
        {
            first = first->next;
        }
        while(first!=nullptr)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode *re = dummy->next;
        delete dummy;
        return re;
    }

private :
    int time{0};
   // ListNode *pre;
    void recur(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return;
        }
        recur(head->next,n);
        time++;
        // if(time==n)
        // {
        //     pre = head->next;
        // }
        if(time==(n+1))
        {
            head->next = head->next->next;
            return;
        }
    }
};



int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2= new ListNode{2};
    ListNode *l3 = new ListNode{3};
    ListNode *l4 = new ListNode{4};
    ListNode *l5 = new ListNode{5};
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    Solution s;
    ListNode *re=s.removeNthFromEnd3(l1,1);
    while(re!=nullptr)
    {
        cout << re->val<<' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
