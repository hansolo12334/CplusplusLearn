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


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root,root);
    }

    bool isMirror(TreeNode *l, TreeNode *r)
    {
        if(r==nullptr && l==nullptr)
        {
            return true;
        }
        if(l==nullptr || r==nullptr)
        {
            return false;
        }
        return (l->val == r->val) && isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }
};


int main()
{
    TreeNode *root = new TreeNode{1};
    TreeNode *l11 = new TreeNode{2};
    TreeNode *l12 = new TreeNode{2};

    TreeNode *l21 = new TreeNode{3};
    TreeNode *l22 = new TreeNode{4};
    TreeNode *l23 = new TreeNode{4};
    TreeNode *l24 = new TreeNode{3};

    root->left = l11;
    root->right = l12;
    l11->left = l21;
    l11->right = l22;
    l12->left = l23;
    l12->right = l24;

    Solution s;
    cout << s.isSymmetric(root) << '\n';
    return 0;
}
