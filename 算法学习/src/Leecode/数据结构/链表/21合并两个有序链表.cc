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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *prehead = new ListNode{};
        ListNode *re = prehead;
        while (list1 && list2)
         //保证prehead的next永远指向list1或list2当前节点的最小值
        {
            if (list1->val<list2->val)
            {
                prehead->next = list1;
                list1 = list1->next;
            }
            else
            {
                prehead->next = list2;
                list2 = list2->next;
            }
            prehead = prehead->next;
        }
        //处理剩余的节点：
        // 合并后 l1 和 l2 最多只有一个还未被合并完，
        // 我们直接将链表末尾指向未合并完的链表即可
        if (list1)
        {
            prehead->next = list1;
        }
        if(list2)
        {
            prehead->next = list2;
        }
        return re->next;
    }
};



int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2 = new ListNode{2};
    ListNode *l3 = new ListNode{4};

    ListNode *l4 = new ListNode{1};
    ListNode *l5 = new ListNode{3};
    ListNode *l6 = new ListNode{4};

    l1->next = l2;
    l2->next = l3;

    l4->next = l5;
    l5->next = l6;

    Solution s;
    ListNode *re=s.mergeTwoLists(l1,l4);
    while(re!=nullptr)
    {
        cout << re->val<<' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
