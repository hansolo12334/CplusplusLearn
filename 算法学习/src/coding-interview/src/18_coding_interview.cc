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

//给定单向链表的一个节点指针，定义一个函数在 `O(1)` 时间删除该节点。
// 假设链表一定存在，并且该节点一定不是尾节点。

class Solution
{
public:
    ListNode* deleteNode(ListNode *node,int pos)
    {
        ListNode *dummyNode = new ListNode{-1};
        dummyNode->next = node;

        while(pos>1)
        {
            node = node->next;
            pos--;
        }
        node->next = node->next->next;

        return dummyNode->next;
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
    int pos = 2;

    auto re=ss.deleteNode(l1,pos);

    while(re)
    {
        std::cout << re->val << ' ';
        re = re->next;
    }
    std::cout << '\n';
    return 0;
}
