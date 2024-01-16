#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};


class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (true)
        {
            if (fast != nullptr && fast->next != nullptr)
            {
                fast = fast->next->next;
            }
            else
            {
                return nullptr;
            }
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }


    ListNode *detectCycle1(ListNode *head)
    {
        unordered_map<ListNode *, int> map;
        while (head != nullptr)
        {
            map[head]++;
            if (map[head] >= 2)
            {
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }
};


int main()
{
    ListNode *l1 = new ListNode{3};
    ListNode *l2 = new ListNode{2};
    ListNode *l3 = new ListNode{0};
    ListNode *l4 = new ListNode{-4};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l2;

    Solution s;
    ListNode *re = s.detectCycle(l1);
    cout << re->val << '\n';
    return 0;
}
