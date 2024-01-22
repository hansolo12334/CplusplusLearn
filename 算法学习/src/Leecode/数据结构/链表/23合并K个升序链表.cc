#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

#include <deque>
#include <queue>


using namespace std;

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


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode{0, nullptr};
        ListNode *re = dummy;

        while (1)
        {
            int listIndex = -1;
            int minEl = INT_MAX;
            int nulls = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] != nullptr && lists[i]->val <= minEl)
                {
                    minEl = lists[i]->val;
                    listIndex = i;
                }
                if(lists[i]==nullptr)
                {
                    nulls++;
                }
            }
            if(nulls==lists.size())
            {
                break;
            }
            //re 尾部添加元素
            if(listIndex!=-1)
            {
                dummy->next = lists[listIndex];
                dummy = dummy->next;
                // 被使用过的列表向前走一步
                lists[listIndex] = lists[listIndex]->next;
            }
        }
        return re->next;
    }
};



int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2 = new ListNode{4};
    ListNode *l3 = new ListNode{5};

    ListNode *l11 = new ListNode{1};
    ListNode *l12 = new ListNode{3};
    ListNode *l13 = new ListNode{4};

    ListNode *l21 = new ListNode{2};
    ListNode *l22 = new ListNode{6};


    l1->next = l2;
    l2->next = l3;

    l11->next = l12;
    l12->next = l13;

    l21->next = l22;

    vector<ListNode *> lists{l1,l11,l21};
    Solution s;
    ListNode *re = s.mergeKLists(lists);

    while(re)
    {
        cout << re->val << ' ';
        re = re->next;
    }
    cout << '\n';

    return 0;
}
