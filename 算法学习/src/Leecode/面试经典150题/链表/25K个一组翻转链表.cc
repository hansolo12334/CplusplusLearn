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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l = 0;
        if(k==1){
            return head;
        }
        vector<ListNode *> vec;
        ListNode *dummy = new ListNode{-1,head};
        ListNode *copy = dummy;
        while (copy)
        {
            vec.push_back(copy);
            l++;
            copy = copy->next;
        }
        ListNode *re;
        l--;
        ListNode *lastT = vec[0];
        k--;
        int endd = (l / (k + 1)) * (k + 1);
        for (int i = 1; i <= endd;)
        {
            ListNode *leftnode = vec[i];
            //切断右边
            vec[i + k]->next = nullptr;
            reverseBetween(leftnode);
            //接回去
            if(i+k+1<=l){
                vec[i]->next = vec[i+k+1];//尾部
            }else{
                vec[i]->next = nullptr;
            }
            lastT->next = vec[i + k];//头部

            lastT = vec[i];
            i = i + k + 1;
        }

        return dummy->next;
    }

    // 反转子区间 输入前先切断右边的节点 让其为nilptr 反转完再接回去
    void reverseBetween(ListNode *leftnode){
        ListNode *pre = nullptr;
        ListNode *cur = leftnode;
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
    ListNode *l6 = new ListNode{6};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;

    Solution s;
    int k = 3;
    ListNode *re = s.reverseKGroup(l1, k);
    while (re)
    {
        cout << re->val << ' ';
        re = re->next;
    }
    cout << '\n';
    return 0;
}
