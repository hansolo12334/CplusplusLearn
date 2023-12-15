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



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int len1{0};
        int len2{0};
        ListNode *ll1 = l1;
        ListNode *ll2 = l2;
        while (ll1 || ll2)
        {
            if(ll1)
            {
                len1++;
                ll1 = ll1->next;
            }
            if(ll2)
            {
                len2++;
                ll2 = ll2->next;
            }
        }
        int fillsize = (len1 < len2) ? (len2 - len1) : (len1 - len2);

        ListNode *newfill{};
        ListNode *newAnother{};
        if (fillsize != 0)
        {
            string fillWhich = (len1 < len2) ? "l1" : "l2"; //0填充右边 1填充左边
            ListNode *temp = new ListNode{0};
            newfill = temp;
            for (int i = 0; i < fillsize-1; i++)
            {
                temp->next = new ListNode{0};
                temp = temp->next;
            }

            temp->next = (fillWhich == "l1") ? l1 : l2;
            newAnother = (fillWhich == "l2") ? l1 : l2;
        }
        else
        {
            newfill = l1;
            newAnother = l2;
        }


        recur(newfill, newAnother);
        if(jinwei)
        {
            ListNode *temp = new ListNode{1};
            temp->next = newfill;
            return temp;
        }
        return newfill;
    }


//方法二 堆栈
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        stack<int> stk1, stk2;
        while(l1||l2)
        {
            if(l1)
            {
                stk1.push(l1->val);
                l1 = l1->next;
            }
            if(l2)
            {
                stk2.push(l2->val);
                l2 = l2->next;
            }
        }
        ListNode *re = nullptr;
        int jinwei = 0;
        while( !stk1.empty() || !stk2.empty() || jinwei!=0)
        {
            int a = stk1.empty() ? 0 : stk1.top();
            int b = stk2.empty() ? 0 : stk2.top();
            if(!stk1.empty()){
                stk1.pop();
            }
            if(!stk2.empty()){
                stk2.pop();
            }
            int ans = a + b + jinwei;
            if(ans>=10){
                ans -= 10;
                jinwei = 1;
            }
            else{
                jinwei = 0;
            }
            ListNode *temp = new ListNode{ans};
            temp->next = re;
            re = temp;
        }
        return re;
    }

private:
    int jinwei{0};
    void recur(ListNode *l1, ListNode *l2)
    {
        if(l1==nullptr && l2==nullptr)
        {
            return;
        }

        recur(l1->next, l2->next);
        l1->val =l1->val+ l2->val+jinwei;
        if(l1->val>=10)
        {
            l1->val -= 10;
            jinwei = 1;
        }
        else
        {
            jinwei = 0;
        }
    }

};




int main()
{
    ListNode *l1 = new ListNode{2};
    ListNode *l2 = new ListNode{4};
    ListNode *l3 = new ListNode{5};

    ListNode *l4 = new ListNode{9};
    ListNode *l5 = new ListNode{9};
    ListNode *l6 = new ListNode{7};
    ListNode *l7 = new ListNode{9};
    ListNode *l8 = new ListNode{8};

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
