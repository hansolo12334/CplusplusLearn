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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode *copy = head;
        vector<ListNode *> vec;
        int l = 0;
        while(copy){
            l++;
            vec.push_back(copy);
            copy = copy->next;
        }
        k = k % l;
        if(k==0){
            return head;
        }

        ListNode *end = vec[l - 1 - k];
        ListNode *newHead = end->next;
        vec[l-1]->next = vec[0];
        end->next = nullptr;

        return newHead;
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
    // l3->next = l4;
    // l4->next = l5;

    Solution s;
    int k = 4;
    ListNode *re = s.rotateRight(l1, k);
    while(re){
        cout << re->val << ' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
