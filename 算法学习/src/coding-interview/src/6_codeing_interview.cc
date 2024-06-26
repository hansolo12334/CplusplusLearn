#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>


struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
     : val{0}
     , next{nullptr}
    {

    }
    ListNode(int x)
     : val{x}
     , next{nullptr}
    {

    }
    ListNode(int x,ListNode *next)
     : val{x}
     , next{next}
    {

    }
};

class Solution
{
public:
    std::vector<int> printListReversingly(ListNode *l1)
    {
        std::vector<int> re;
        while(l1){
            re.push_back(l1->val);
            l1 = l1->next;
        }
        std::reverse(re.begin(), re.end());
        return re;
    }

    std::vector<int> printListReversingly2(ListNode *l1)
    {
        std::vector<int> re;
        std::stack<int> stk;
        while (l1)
        {
            stk.push(l1->val);
            l1 = l1->next;
        }
        while(!stk.empty())
        {
            re.push_back(stk.top());
            stk.pop();
        }
        return re;
    }
};




int main()
{
    ListNode *l1 = new ListNode{2};
    ListNode *l2 = new ListNode{3};
    ListNode *l3 = new ListNode{5};
    l1->next = l2;
    l2->next = l3;

    Solution ss;
    auto re{ss.printListReversingly2(l1)};

    for(auto r: re)
    {
        std::cout << r << ' ';
    }
    std::cout << '\n';
    return 0;
}
