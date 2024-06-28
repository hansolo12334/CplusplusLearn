#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;

    ListNode()
     : val{0}
     , next{nullptr}
    {

    }
    ListNode(int x)
     : val{x}
     , next{nullptr}
    {

    }
    ListNode(int x,ListNode *next)
     : val{x}
     , next{next}
    {

    }
};



class Solution
{
    // 22 链表中倒数第 k 个节点
public:
    int FindKthToTail(ListNode *node,int k)
    {
        ListNode *dummyNode = new ListNode{-1};
        dummyNode->next = node;

        ListNode *phead = node;
        ListNode *pre = node;

        while(k>0)
        {
            pre = pre->next;
            k--;
        }
        while(pre)
        {
            pre = pre->next;
            phead = phead->next;
        }

        return phead->val;
    }
};


int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2 = new ListNode{4};
    ListNode *l3 = new ListNode{6};
    ListNode *l4 = new ListNode{8};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution ss;
    int k = 2;

    auto re=ss.FindKthToTail(l1,k);

    std::cout << re;
    std::cout << '\n';
    return 0;
}
