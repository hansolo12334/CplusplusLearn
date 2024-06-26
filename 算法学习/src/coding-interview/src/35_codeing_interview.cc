#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;

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
    //头插法
    ListNode* copyList(ListNode *input)
    {
        ListNode *dummyNode = new ListNode{-1};
        ListNode *re = dummyNode;
        std::vector<ListNode *> vec1;
        while(input){
            // map[input] = input->next;
            // map1[input] = input->random;
            vec1.push_back(input);
            input = input->next;
        }
        for(auto vec :vec1)
        {
            ListNode *node = new ListNode{vec->val};
            node->next = vec->next;
            node->random = vec->random;
            dummyNode->next = node;
            dummyNode = dummyNode->next;
        }


        return re->next;
    }
};


int main()
{
    ListNode *l1 = new ListNode{1};
    ListNode *l2 = new ListNode{2};
    ListNode *l3 = new ListNode{3};
    ListNode *l4 = new ListNode{4};
    l1->next = l2;
    l2->next = l3;


    l1->random = l3;
    l2->random = l4;
    l3->random = l1;
    l4->random = l2;

    Solution ss;
    auto re{ss.copyList(l1)};

    while(re){
        std::cout << re->val << ' ';
        std::cout << re->random->val << '\n';
        if(re->random->random){
            std::cout << re->random->random->val << '\n';
        }
        re = re->next;
    }
    std::cout << '\n';
    return 0;
}
