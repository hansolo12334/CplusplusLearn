#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;



//  * Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;


      ListNode()
        : val(0)
        , next(nullptr)
        {}
      ListNode(int x)
        : val(x)
        , next(nullptr)
        {}
      ListNode(int x, ListNode *next)
        : val(x)
        , next(next)
        {}
  };

class Solution {
public:
//解法1
    vector<int> reverseBookList(ListNode* head) {
        recur(head);
        return res;
    }

//解法2
    vector<int> reverseBookList1(ListNode* head) {
        stack<int> stk;
        while(head!=nullptr)
        {
            stk.push(head->val);
            head = head->next;
        }
        vector<int> res{};
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
//解法三
vector<int> reverseBookList2(ListNode* head) {
    vector<int> res{};
    while(head!=nullptr)
    {
        res.push_back(head->val);
        head = head->next;
    }
    reverse(res.begin(), res.end());
    return res;
}

private :
    vector<int> res;
    void recur(ListNode *head)
    {
        //
        if (head == nullptr)
        {
            return;
        }

        recur(head->next);

        res.push_back(head->val);
    }
};

int main()
{
    ListNode *l1 = new ListNode{3};
    ListNode *l2= new ListNode{6};
    ListNode *l3 = new ListNode{4};
    ListNode *l4 = new ListNode{1};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution s;
    vector res{s.reverseBookList(l1)};
    for(int r:res)
    {
        std::cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
