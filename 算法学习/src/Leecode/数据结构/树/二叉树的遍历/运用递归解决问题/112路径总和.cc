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


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        {
            return false;
        }
        if(!root->left && !root->right)
        {
            return targetSum == root->val;
        }

        return hasPathSum(root->left, targetSum-root->val)||
        hasPathSum(root->right, targetSum-root->val);
    }

    bool hasPathSum1(TreeNode *root,int targetSum)
    {
        if(!root)
        {
            return false;
        }
        stack<pair<TreeNode*,int>> stk;

        stk.push({root,targetSum});
        int lastSum = 0;
        while (!stk.empty())
        {
            TreeNode *temp = stk.top().first;
            int sum = stk.top().second;
            stk.pop();

            if(temp->left==nullptr&& temp->right==nullptr)
            {
                if(sum==temp->val)
                {
                    return true;
                }
            }

            if (temp->right)
            {
                stk.push({temp->right,sum-temp->val});
            }
            if(temp->left)
            {
                stk.push({temp->left,sum-temp->val});
            }


        }
        return false;
    }
};


int main()
{
    TreeNode *root = new TreeNode{5};

    TreeNode *l11 = new TreeNode{4};
    TreeNode *l12 = new TreeNode{8};

    TreeNode *l21 = new TreeNode{11};
    TreeNode *l23 = new TreeNode{13};
    TreeNode *l24 = new TreeNode{4};

    TreeNode *l31 = new TreeNode{7};
    TreeNode *l32 = new TreeNode{2};
    TreeNode *l36 = new TreeNode{1};

    root->left = l11;
    root->right = l12;

    l11->left = l21;

    l12->left= l23;
    l12->right = l24;

    l21->left = l31;
    l21->right = l32;

    l24->right = l36;

    int targetSum = 22;

    Solution s;
    cout << s.hasPathSum1(root,targetSum) << '\n';
    return 0;
}
