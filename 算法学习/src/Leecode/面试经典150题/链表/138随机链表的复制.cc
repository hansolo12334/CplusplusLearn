#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>
#include<map>
#include<unordered_set>


using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *re = new Node{0};
        Node *prere = re;

        vector<Node *> orignal_nodeVect{};
        vector<Node *> copy_vect{};
        //把原始链表装入向量 顺便 新开辟re 复制一遍原始链表的val值
        while(head){
            orignal_nodeVect.push_back(head);

            prere->next = new Node{head->val};
            copy_vect.push_back(prere->next);
            prere = prere->next;


            head = head->next;
        }

        for (int i = 0; i < orignal_nodeVect.size(); i++)
        {
            //找到每个节点 的random对应的地址  指向的节点的下标
            auto index = find(orignal_nodeVect.begin(), orignal_nodeVect.end(), orignal_nodeVect[i]->random);
            if(index!=orignal_nodeVect.end()){
                copy_vect[i]->random = copy_vect[index-orignal_nodeVect.begin() ];
            }
        }
            return re->next;
    }

//方法二 递归
public:
    unordered_map<Node *, Node *> cachedNode;
    Node *copyRandomList1(Node *head)
    {
        if(head==nullptr){
            return nullptr;
        }
        if(!cachedNode.count(head)){
            Node *headNew = new Node{head->val};
            cachedNode[head] = headNew;
            headNew->next = copyRandomList1(head->next);
            headNew->random = copyRandomList1(head->random);
        }
        return cachedNode[head];
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

    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;


    Solution s;
    Node *re = s.copyRandomList(n1);
    while(re){
        cout << re->val << ' ';
        if(re->random){
            cout << re->random->val << '\n';
        }
        cout << '\n';
        re = re->next;
    }

    return 0;
}
