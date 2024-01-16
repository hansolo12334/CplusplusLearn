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
    int countNodes(TreeNode* root) {

        queue<TreeNode *> que;
        que.push(root);
        int re=0;
        while (!que.empty())
        {
            TreeNode *temp = que.front();
            if(temp==nullptr)
            {
                break;
            }
            re++;
            que.pop();
            if(temp->left)
            {
                que.push(temp->left);
            }
            if(temp->right)
            {
                que.push(temp->right);
            }
        }
        return re;
    }


// 深度遍历 递归
    int countNodes1(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        return countNodes1(root->left) + countNodes1(root->right) + 1;
    }
};



int main()
{
    TreeNode *root = new TreeNode{1};
    TreeNode *t11 = new TreeNode{2};
    TreeNode *t12 = new TreeNode{3};
    TreeNode *t21 = new TreeNode{4};
    TreeNode *t22 = new TreeNode{5};
    TreeNode *t23 = new TreeNode{6};

    root->left = t11;
    root->right = t12;
    t11->left = t21;
    t11->right = t22;
    t12->left = t23;

    Solution s;
    cout << s.countNodes1(root) << '\n';
    return 0;
}
