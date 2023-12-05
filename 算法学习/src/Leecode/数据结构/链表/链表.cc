#include<iostream>



class ListNode
{
    public :
        int val{};
        ListNode *next{};
        ListNode(int x)
            : val{x}
            , next{NULL}
            {

            }
};

int main()
{
    ListNode *l1=new ListNode{1};
    ListNode *l2=new ListNode{1};
    ListNode *l3=new ListNode{1};

    l1->next = l2;


    l2->next = l3;


    return 0;
}
