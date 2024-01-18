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

//中序遍历 左子树->根节点->右子树
class Solution {
public:

    //方法一 递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re{};
        inorder(root, re);
        return re;
    }

    void inorder(TreeNode *root, vector<int> &re)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left, re);
        re.push_back(root->val);
        inorder(root->right, re);
    }
    //方法二 迭代
     vector<int> inorderTraversal1(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        vector<int> re;
        stack<TreeNode *> stk{};

        while(root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            re.push_back(root->val);
            root = root->right;
        }
        return re;
     }
};


int main()
{
    TreeNode *root = new TreeNode{1};
    TreeNode *l12 = new TreeNode{2};
    TreeNode *l31 = new TreeNode{3};

    root->right = l12;
    l12->left=l31;

    Solution s;
    vector<int> re = s.inorderTraversal1(root);

    for(int r:re)
    {
        std::cout << r << ' ';
    }
    std::cout << '\n';

    return 0;
}
