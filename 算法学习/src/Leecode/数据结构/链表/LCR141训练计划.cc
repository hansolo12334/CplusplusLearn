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
        , next(NULL)
        {}
  };


//递归 在回溯时
class Solution {
public:
    ListNode* trainningPlan(ListNode* head) {

        recur(head);

        return res->next;
    }



    private :
        ListNode *now=new ListNode();
        ListNode *res = now;


        void recur(ListNode *head)
         {
            if (head==nullptr)
            {
                return;
            }
            recur(head->next);

            ListNode *temp = new ListNode{head->val};

            now->next = temp;
            now = now->next;
            // if (now->next==nullptr)
            // {

            // }
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
    ListNode *re=s.trainningPlan(l1);
    while(re!=nullptr)
    {
        cout << re->val<<' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
