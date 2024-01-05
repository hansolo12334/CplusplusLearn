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

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *copy = node;
        while(node){
            if(node->next && node->next->next){
                node->val = node->next->val;
            }
            if(!node->next->next){
                break;
            }
            node = node->next;
        }
        node->val = node->next->val;
        node->next=nullptr;
    }

//官方解法
    void deleteNode1(ListNode* node) {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};


int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2 = new ListNode{2};
    ListNode *l3 = new ListNode{3};
    ListNode *l4 = new ListNode{4};
    ListNode *l5 = new ListNode{5};
    // ListNode *l6 = new ListNode{6};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    // l5->next = l6;

    Solution s;

    s.deleteNode1(l3);
    while(l1){
        cout << l1->val<< ' ';
        l1=l1->next;
    }
    cout << '\n';
    return 0;
}
