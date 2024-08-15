#include <algorithm>
#include <iostream>


struct ListNode
{
    ListNode *next = nullptr;
    int val;
    ListNode(int val, ListNode *next) : val{val}, next{next}
    {
    }
    ListNode() : val{0}, next{nullptr}
    {
    }
    ListNode(int val) : val{val}, next{nullptr}
    {
    }
};

class Sulotion
{
public:
    Sulotion()
    {
    }

    ListNode *findFirstSameNode(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        int l1_size{0};
        int l2_size{0};
        while (t1)
        {
            l1_size++;
            t1 = t1->next;
        }
        while (t2)
        {
            l2_size++;
            t2 = t2->next;
        }
        int d_size = l1_size - l2_size;
        if (d_size < 0)
        { //l1比l2短 l2先走
            while (d_size < 0)
            {
                l2 = l2->next;
                d_size++;
            }
        }
        else
        {
            while (d_size > 0)
            {
                l1 = l1->next;
                d_size--;
            }
        }
        while (l1 && l2)
        {
            if (l1->val == l2->val)
            {
                return l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        return l2;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(5);
    ListNode *l4 = new ListNode(6);
    ListNode *l5 = new ListNode(7);

    ListNode *l11 = new ListNode(2);
    ListNode *l12 = new ListNode(4);
    ListNode *l13 = new ListNode(5);
    ListNode *l14 = new ListNode(5);
    ListNode *l15 = new ListNode(6);
    ListNode *l16 = new ListNode(7);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    l11->next = l12;
    l12->next = l13;
    l13->next = l14;
    l14->next = l15;
    l15->next = l16;

    Sulotion sss;
    auto re = sss.findFirstSameNode(l1, l11);

    while (re)
    {
        std::cout << re->val << ' ';
        re = re->next;
    }
    std::cout << '\n';
    return 0;
}
