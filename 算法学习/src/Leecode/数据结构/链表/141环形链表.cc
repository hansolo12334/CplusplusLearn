#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

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

//方法: 哈希表 来储存已经访问过的节点 如果再次访问相同节点则返回true
// 有环形链表
class Solution {
public:
    bool hasCycle(ListNode *head) {

            recro(head);
            return has;
    }

//方法二 快慢指针 龟兔赛跑 如果兔子超了乌龟一次 说明有环
    bool hasCycle1(ListNode *head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return false;
        }
        ListNode *fast{head->next};
        ListNode *slow{head};
        while (fast!=slow)
        {
            if(fast==nullptr || fast->next==nullptr)
            {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }


private:
    bool has{false};
    unordered_map<ListNode*,int> map;

    void recro(ListNode *head)
    {
        if(head==nullptr)
        {
            return;
        }
        if(map[head]>=1)
        {
            has = true;
            return;
        }
        else{
            map[head]++;
        }
        recro(head->next);

    }
};

int main()
{
    ListNode *l1 = new ListNode{3};
    ListNode *l2 = new ListNode{2};
    ListNode *l3 = new ListNode{0};
    ListNode *l4 = new ListNode{4};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l2;

    Solution s;
    std::cout<< s.hasCycle1(l1)<<'\n';

    return 0;
}
