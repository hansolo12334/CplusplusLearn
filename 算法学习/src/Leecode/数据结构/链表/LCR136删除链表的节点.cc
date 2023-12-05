#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


struct ListNode {

    int val;
    ListNode *next;

    ListNode(int x)
        : val(x)
        , next(NULL)
        {}
  };





class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val)
        {
            head = head->next;
            return head;
        }

        ListNode *re = head;
        while (head != nullptr)
        {
            ListNode *temp = head->next;
            if(temp!=nullptr)
            {
                if ( (temp->val==val) &&(temp->next!=nullptr))
                {
                    head->next = temp->next;
                    return re;
                }
                else if ( (temp->val==val) &&(temp->next==nullptr))
                {
                    head->next = nullptr;
                    return re;
                }
            }
            head = temp;
        }
        return re;
    }

//解法2
    ListNode* deleteNode2(ListNode* head, int val) {
        if(head->val==val)
        {
            head = head->next;
            return head;
        }
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(cur!=nullptr && cur->val!=val){
            pre = cur;
            cur = cur->next;
        }
        if (cur!=nullptr)
        {
            pre->next = cur->next;
        }
        return head;
    }
};

int main()
{
    ListNode *l1 = new ListNode{4};
    ListNode *l2= new ListNode{5};
    ListNode *l3 = new ListNode{1};
    ListNode *l4 = new ListNode{9};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution s;
    ListNode *re=s.deleteNode2(l1, 9);
    while(re!=nullptr)
    {
        cout << re->val<<' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
