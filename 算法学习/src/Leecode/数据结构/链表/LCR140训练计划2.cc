#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


struct ListNode {

    int val;
    ListNode *next;
    ListNode()
        : val(0)
        , next(nullptr)
        {}
    ListNode(int x)
        : val(x)
        , next(NULL)
        {}
    ListNode(int x,ListNode*next)
        : val(x)
        , next(next)
        {}
  };



//双指针
class Solution {
public:

    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode *left = head;
        ListNode *right = head;
        for (int i = 0; i < cnt;i++)//右指针先走cnt
        {
            right = right->next;
        }

        while(right)
        //然后左右指针一起走，直到右指针到头，此时左指针刚好到了倒数第cnt个节点，输出左指针
        {
            right = right->next;
            left = left->next;
        }

        return left;
    }


};

int main()
{
    ListNode *l1 = new ListNode{2};
    ListNode *l2= new ListNode{4};
    ListNode *l3 = new ListNode{7};
    ListNode *l4 = new ListNode{8};

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;


    Solution s;
    ListNode *re=s.trainingPlan(l1,2);
    while(re!=nullptr)
    {
        cout << re->val<<' ';
        re = re->next;
    }
    cout << '\n';
    return 0;

}
