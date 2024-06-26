#include<iostream>
#include<vector>
#include<algorithm>

struct ListNode
{
    int val;
    ListNode *next;

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
public:
    //头插法
    ListNode* reverseList(ListNode *input)
    {
        if(!input || !input->next){
            return input;
        }
        ListNode *dummy = new ListNode{-1};
        ListNode *p = input;
        ListNode *q = input->next;
        while(q){
            ///核心
            p->next = dummy->next;
            dummy->next = p;
            ///

            p = q;
            q = p->next;
        }
        //将q的头节点依次摘下来 用头插法插入到p的头部
        p->next = dummy->next;
        return p;
    }
};


int main()
{
    ListNode *l1 = new ListNode{2};
    ListNode *l2 = new ListNode{3};
    ListNode *l3 = new ListNode{5};
    l1->next = l2;
    l2->next = l3;

    Solution ss;
    auto re{ss.reverseList(l1)};

    while(re){
        std::cout << re->val << ' ';
        re = re->next;
    }
    std::cout << '\n';
    return 0;
}
