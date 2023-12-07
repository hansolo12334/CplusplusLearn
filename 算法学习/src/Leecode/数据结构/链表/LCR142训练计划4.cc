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
    ListNode(int x,ListNode*next)
        : val(x)
        , next(next)
        {}
  };



/*给定两个以 有序链表 形式记录的训练计划 l1、l2，分别记录了两套核心肌群训练项目编号，请合并这两个训练计划，按训练项目编号 升序 记录于链表并返回。

注意：新链表是通过拼接给定的两个链表的所有节点组成的。*/

class Solution {
public:
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {

        ListNode *now = new ListNode{};
        ListNode *re = now;

        while (l1 && l2)
        {
            if(l1->val<l2->val)
            {

                now->next = l1;
                l1 = l1->next;
            }
            else
            {
                now->next = l2;
                l2 = l2->next;
            }
            now = now->next;
        }

        if(l1)
        {
            now->next = l1;
        }
        if(l2)
        {
            now->next = l2;
        }
        return re->next;
    }
};



int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2= new ListNode{2};
    ListNode *l3 = new ListNode{4};

    ListNode *l4 = new ListNode{1};
    ListNode *l5 = new ListNode{3};
    ListNode *l6 = new ListNode{4};


    l1->next = l2;
    l2->next = l3;


    l4->next = l5;
    l5->next = l6;


    Solution s;
    ListNode *re=s.trainningPlan(l1,l4);
    while(re!=nullptr)
    {
        cout << re->val<<' ';
        re = re->next;
    }
    cout << '\n';
    return 0;

}
