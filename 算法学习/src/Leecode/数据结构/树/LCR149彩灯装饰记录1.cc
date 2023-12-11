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


//二叉树的 广度优先遍历  利用队列的先进先出来实现 每次处理队头的节点 将节点的左右子节点加到队尾 弹出队头
class Solution
{
public:
    vector<int> decorateRecord(TreeNode *root)
    {
        if(root==nullptr)
        {
            return {};
        }
        vector<int> re;
        queue<TreeNode*> que;

        que.push(root);
        re.push_back(root->val);

        while(!que.empty())
        {
            if(que.front()->left)
            {
                re.push_back(que.front()->left->val);
                que.push(que.front()->left);
            }
            if(que.front()->right)
            {
                re.push_back(que.front()->right->val);
                que.push(que.front()->right);
            }
            que.pop();
        }
        return re;
    }
};


int main()
{
    TreeNode *root = new TreeNode{8};

    TreeNode *t11 = new TreeNode{17};
    TreeNode *t12 = new TreeNode{21};
    TreeNode *t21 = new TreeNode{18};
    TreeNode *t22 = new TreeNode{6};

    root->left = t11;
    t11->left = t21;
    root->right = t12;
    t12->right = t22;

    Solution s;
    vector<int> re = s.decorateRecord(root);
    for(int r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
