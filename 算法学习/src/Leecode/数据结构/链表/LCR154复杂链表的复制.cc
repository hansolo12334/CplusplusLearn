#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node *> vNode{};
        vector<Node *> vNode_or{};

        Node *now = new Node{0};
        Node *re = now;
        while(head)
        {
            vNode_or.push_back(head);

            Node *temp = new Node{head->val};
            now->next= temp;
            now = now->next;
            head = head->next;

            vNode.push_back(now);

        }

        for (int i = 0; i < vNode_or.size(); i++)
        {
            // Node *random = vNode_or[i]->random;
            // for (int j = 0; j < vNode_or.size();j++)
            // {
            //     if(vNode_or[j]==random)
            //     {
            //         vNode[i]->random = vNode[j];
            //         break;
            //     }
            // }
            auto it= find(vNode_or.begin(), vNode_or.end(), vNode_or[i]->random);
            if(it!=vNode_or.end())
            {
                vNode[i]->random = vNode[it - vNode.begin()];
            }
        }


        return re->next;
    }
};




int main()
{
    Node *n1 = new Node{7};
    Node *n2 = new Node{13};
    Node *n3 = new Node{11};
    Node *n4 = new Node{10};
    Node *n5 = new Node{1};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution s;
    Node *re = s.copyRandomList(n1);
    while(re)
    {
        std::cout << re->val << " " << re->random << '\n';
        re = re->next;
    }
    return 0;
}
