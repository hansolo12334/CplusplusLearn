#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

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
//方法一 递归
    ListNode* reverseList(ListNode* head) {
        ListNode *re = now;
        recur(head);
        return re->next;
    }

    void recur(ListNode *head)
    {
        if(head==nullptr)
        {
            return;
        }
        recur(head->next);

        now->next = new ListNode{head->val};
        now = now->next;
    }
private:
    ListNode *now = new ListNode{};


//方法二 双指针
    ListNode* reverseList1(ListNode* head) {
        ListNode *cur = head;    //头部
        ListNode *pre = nullptr; //尾部
        while(cur!=nullptr)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};


int main()
{
    ListNode *l1 = new ListNode{2};
    ListNode *l2 = new ListNode{4};
    ListNode *l3 = new ListNode{5};

    ListNode *l4 = new ListNode{5};
    ListNode *l5 = new ListNode{6};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    Solution s;
    ListNode *re = s.reverseList1(l1);
    while(re)
    {
        cout << re->val << ' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
