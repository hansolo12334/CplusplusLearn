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

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
        {
            return head;
        }
        vector<ListNode *> vec{};
        ListNode *temp = new ListNode{0};
        temp->next = head;
        ListNode *pre = temp;
        while (temp)
        {
            vec.push_back(temp);
            temp = temp->next;
        }
        int n = vec.size();
        ListNode *be = vec[left - 1];
        for (int i = right; i >= left; i--)
        {
            be->next = new ListNode{vec[i]->val};
            be = be->next;
        }
        if (right < (n - 1))
        {
            be->next = vec[right + 1];
        }

        return pre->next;
    }

    ListNode *reverseBetween1(ListNode *head, int left, int right)
    {
        ListNode *dummyNode = new ListNode{-1};
        dummyNode->next = head;

        ListNode *pre = dummyNode;
        //1 在虚拟头节点先走 left-1 步，来到left节点的前一个节点
        for (int i = 0; i < left - 1;i++){
            pre = pre->next;
        }
        //2 从pre再走right-left+1步数 来到 right节点
        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1;i++){
            rightNode = rightNode->next;
        }
        //3 切断出一个子链表(截取链表)
        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next;

        pre->next = nullptr;
        rightNode->next=nullptr;
        //4 反转链表的子区间
        reverseLinkList(leftNode);

        //5 接回原来的链表中
        pre->next = rightNode;
        leftNode->next = curr;

        return dummyNode->next;
    }


    void reverseLinkList(ListNode *head){
        ListNode *pre = nullptr;
        ListNode *cur=head;
        while(cur!=nullptr){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
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
    int left = 2;
    int right = 4;
    ListNode *re = s.reverseBetween1(l1, left, right);
    while (re)
    {
        cout << re->val << ' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
