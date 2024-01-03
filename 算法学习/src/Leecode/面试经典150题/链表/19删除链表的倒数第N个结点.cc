#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <unordered_set>


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        n++;
        ListNode *copy = new ListNode{-1};
        copy->next = head;
        ListNode *re = copy;
        recur(copy, n);
        return re->next;
    }
    void recur(ListNode *head,int &n)
    {

        if (head == nullptr)
        {
            return;
        }
        recur(head->next, n);
        n--;
        if (n == 0)
        {
            head->next = head->next->next;
        }

    }
    //官方解法 栈
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        stack<ListNode *> stk;
        ListNode *cur = dummy;
        while(cur){
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n;i++){
            stk.pop();
        }
        ListNode *prev = stk.top();
        prev->next = prev->next->next;
        return dummy->next;
    }
    //官方解法 双指针
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode *dummyNode = new ListNode{-1, head};
        ListNode *fast = dummyNode;
        ListNode *slow = dummyNode;
        for (int i = 0; i < n+1;i++){
            fast = fast->next;
        }
        for (int j = 0; fast != nullptr;j++){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummyNode->next;
    }
};


int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2 = new ListNode{2};
    ListNode *l3 = new ListNode{3};
    ListNode *l4 = new ListNode{4};
    ListNode *l5 = new ListNode{5};
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    Solution s;
    int n = 2;
    ListNode *re = s.removeNthFromEnd2(l1, n);
    while(re){
        cout << re->val << '\n';
        re = re->next;
    }

    return 0;
}
