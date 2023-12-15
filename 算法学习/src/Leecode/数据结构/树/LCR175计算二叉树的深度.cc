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

class Solution {
public:
//方法一 后续遍历 dfs
    int calculateDepth(TreeNode* root) {

        return recur(root);
    }

    int recur(TreeNode *leaf)
    {
        int deepl{}, deepr{};
        if(leaf==nullptr)
        {
            return 0;
        }
        else
        {
            deepl = recur(leaf->left);
            deepr = recur(leaf->right);
            if(deepl>deepr)
            {
                return deepl+1;
            }
            else
            {
                return deepr + 1;
            }
        }
    }

// 方法二 层序遍历 bfs
    int calculateDepth2(TreeNode* root) {

    }
};


int main()
{
    TreeNode *root = new TreeNode{0};

    TreeNode *t11 = new TreeNode{2};
    TreeNode *t12 = new TreeNode{4};

    TreeNode *t21 = new TreeNode{1};
    TreeNode *t22 = new TreeNode{3};
    TreeNode *t23 = new TreeNode{-1};

    TreeNode *t31 = new TreeNode{5};
    TreeNode *t32 = new TreeNode{1};
    TreeNode *t33 = new TreeNode{6};
    TreeNode *t34 = new TreeNode{8};


    root->left = t11;
    t11->left = t21;
    t21->left = t31;
    t21->right = t32;

    root->right = t12;
    t12->left = t22;
    t12->right = t23;
    t22->right = t33;
    t23->right = t34;

    Solution s;
    int re = s.calculateDepth(root);
    cout << re << '\n';
    return 0;
}
