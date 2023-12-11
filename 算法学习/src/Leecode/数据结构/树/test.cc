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


//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {}

    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x)
        , left(left)
        , right(right)
    {}

};



void recur(TreeNode *t1,TreeNode *t2)
{
    if (t1==nullptr && t2==nullptr)
    {
        return;
    }
    else if(t1==nullptr)
    {
        cout << t2->val << ' ';
        recur(t1, t2->right);
    }
    else if (t2 == nullptr)
    {
        cout << t1->val << '\n';
        recur(t1->left, t2);
    }
    else if(t1&&t2)
    {
        cout << t1->val << ' ' << t2->val << '\n';
        recur(t1->left, t2->right);
    }
}

int main()
{

    TreeNode *root1 = new TreeNode{1};
    TreeNode *l11 = new TreeNode{7};
    TreeNode *l12 = new TreeNode{5};
    TreeNode *l21 = new TreeNode{6};
    TreeNode *l31 = new TreeNode{1};

    root1->left = l11;
    root1->right = l12;
    l11->left = l21;
    l21->left = l31;

    recur(root1->left, root1->right);
    return 0;
}
