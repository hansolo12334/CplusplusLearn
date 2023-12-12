#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;


    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        recur(l1, l2);

        return re->next;
    }

    void recur(ListNode *l1, ListNode *l2)
    {
        if(!l1 && !l2 )
        {
            if (jinwei)
            {
                ListNode *temp = new ListNode{1};
                now->next = temp;
                now = now->next;
            }
            return;
        }
        else if(l1&&l2)
        {
            cout << l1->val << ' ' << l2->val << '\n';

            ListNode *temp = new ListNode{l1->val + l2->val};
            if(jinwei)
            {
                temp->val += 1;
            }
            if(temp->val>=10)
            {
                temp->val -= 10;
                jinwei = true;
            }
            else
            {
                jinwei = false;
            }
            now->next = temp;
            now = now->next;
            recur(l1->next, l2->next);
        }
        else if(l1 && !l2)
        {
            cout << l1->val << ' ' << ' ' << '\n';
            ListNode *temp = new ListNode{l1->val};
            if(jinwei)
            {
                temp->val += 1;
                if(temp->val>=10)
                {
                    temp->val -= 10;
                }
                else
                {
                    jinwei = false;
                }
            }
            now->next = temp;
            now = now->next;
            recur(l1->next, l2);
        }
        else if(l2 && !l1)
        {
            cout << ' ' << ' ' << l2->val << '\n';
            ListNode *temp = new ListNode{l2->val};
            if(jinwei)
            {
                temp->val += 1;
                if(temp->val>=10)
                {
                    temp->val -= 10;
                }
                else
                {
                    jinwei = false;
                }
            }
            now->next = temp;
            now = now->next;
            recur(l1, l2->next);
        }
    }
private:
    ListNode *now = new ListNode{};
    ListNode *re = now;
    bool jinwei{false};

//方法二
public:
    ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2)
    {
        ListNode *now = new ListNode{};
        ListNode *re = now;
        int carry{0};
        while (l1 != nullptr || l2 != nullptr)
        {
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            cout << x << ' ' << y << '\n';

            int sum{x + y+carry};
            carry = sum / 10;
            sum = sum % 10;

            ListNode *temp = new ListNode{sum};
            now->next = temp;
            now = now->next;

            if (l1)
            {
                l1 = l1->next;
            }
            if(l2)
            {
                l2 = l2->next;
            }
        }
        if(carry==1)
        {
            now->next = new ListNode{carry};
        }
        return re->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode{2};
    ListNode *l2 = new ListNode{4};
    ListNode *l3 = new ListNode{5};

    ListNode *l4 = new ListNode{5};
    ListNode *l5 = new ListNode{6};
    ListNode *l6 = new ListNode{4};
    ListNode *l7 = new ListNode{9};
    ListNode *l8 = new ListNode{9};

    l1->next = l2;
    l2->next = l3;

    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;


    Solution s;
    ListNode *re = s.addTwoNumbers1(l1, l4);
    while(re)
    {
        cout << re->val << ' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
