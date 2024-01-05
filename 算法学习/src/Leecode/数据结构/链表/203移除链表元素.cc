#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

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


class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyNode = new ListNode{-1, head};
        ListNode *lastNode = dummyNode;
        ListNode *now = head;
        while(now){
            if(now->val==val){
                lastNode->next = now->next;
                now = now->next;
            }
            else{
                lastNode = lastNode->next;
                now = now->next;
            }

        }
        return dummyNode->next;
    }
};



int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2 = new ListNode{2};
    ListNode *l3 = new ListNode{3};
    ListNode *l4 = new ListNode{4};
    ListNode *l5 = new ListNode{6};
    ListNode *l6 = new ListNode{6};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;

    Solution s;
    int val = 6;
    ListNode *re = s.removeElements(l1, val);
    while(re){
        cout << re->val<< ' ';
        re=re->next;
    }
    cout << '\n';
    return 0;
}
