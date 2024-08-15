#include<iostream>
#include<algorithm>


struct ListNode
{
    ListNode *next = nullptr;
    int val;
    ListNode(int val,ListNode *next)
    : val{val}
    , next{next}
    {

    }
    ListNode()
    : val{0}
    , next{nullptr}
    {

    }
    ListNode(int val)
     : val{val}
     , next{nullptr}
     {

     }
};


class Sulotion
{
public:
    Sulotion()
    {

    }

    ListNode* merge(ListNode *head1,ListNode *head2)
    {
        if(!head1 )
        {
            return head2;
        }
        if(!head2)
        {
            return head1;
        }
        ListNode *dummyNode;
        ListNode *re = new ListNode(0);
        dummyNode = re;

        while (head1 && head2)
        {
            if(head1->val<head2->val)
            {
                ListNode *temp = new ListNode(head1->val);
                re->next = temp;
                head1 = head1->next;
            }
            else
            {
                ListNode *temp = new ListNode(head2->val);
                re->next = temp;
                head2 = head2->next;
            }
            re = re->next;
        }

        if(head1){
            re->next = head1;
        }
        else if(head2){
            re->next = head2;
        }
        return dummyNode->next;
    }
};


int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(5);

    ListNode *l11 = new ListNode(2);
    ListNode *l12 = new ListNode(4);
    ListNode *l13 = new ListNode(5);

    l1->next = l2;
    l2->next = l3;

    l11->next = l12;
    l12->next = l13;


    Sulotion ss;

    auto re = ss.merge(l1, l11);
    while(re)
    {
        std::cout << re->val << '\n';
        re = re->next;
    }
    return 0;
}
