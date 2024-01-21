#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

#include <deque>
#include <queue>


using namespace std;


class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {


        vector<Node *> nextList;


        Node *re = head;

        Node *tail;
        while (head != nullptr)
        {
            //找到有child的节点 停止 把之前的节点先加入
            while (head && head->child==nullptr)
            {
                if(head->next==nullptr)
                {
                    tail = head;
                }
                head = head->next;
            }
            //把 有child的节点的下一个节点记录
            if(head && head->next){
                nextList.push_back(head->next);
                head->next->prev = nullptr; //切断
                head->next = nullptr; //切断

            }
            //next链接child
            if(head)
            {
                head->child->prev = head; // next prev 链接
                head->next = head->child;
                head->child = nullptr; // child指向null
                head = head->next;
            }

        }
        head = tail;
        // 链接每层 剩下的部分
        for (int i = nextList.size() - 1; i >= 0; i--)
        {
            Node *temp = nextList[i];
            head->next = temp;
            temp->prev = head;
            while(1)
            {
                if(temp->next)
                {
                    temp=temp->next;
                }
                else{
                    break;
                }
            }
            head = temp;
        }
        return re;
    }
};



int main()
{
    Node *n1 = new Node{1};
    Node *n2 = new Node{2};
    Node *n3 = new Node{3};
    Node *n4 = new Node{4};
    Node *n5 = new Node{5};
    Node *n6 = new Node{6};
    Node *n7 = new Node{7};
    Node *n8 = new Node{8};
    Node *n9 = new Node{9};
    Node *n10 = new Node{10};
    Node *n11 = new Node{11};
    Node *n12 = new Node{12};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    n6->prev = n5;
    n5->prev = n4;
    n4->prev = n3;
    n3->prev = n2;
    n2->prev = n1;

    n3->child = n7;

    n7->next = n8;
    n8->next = n9;
    n9->next = n10;

    n10->prev = n9;
    n9->prev = n8;
    n8->prev = n7;

    n8->child = n11;

    n11->next = n12;
    n12->prev = n11;

    Solution s;
    Node *re = s.flatten(n1);

    while(re)
    {
        cout << re->val << ' ';

        re = re->next;
        if(re)
        {
            cout << re->prev->val<<"   ";
        }

    }
    cout << '\n';
    return 0;
}
