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

//方法一 使用数组
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        vector<TreeNode *> que;
        vector<vector<int>> re;

        que.push_back(root);

        while(!que.empty())
        {
            vector<TreeNode *> temp;
            vector<int> r;
            for (auto leaf : que)
            {
                r.push_back(leaf->val);
                if(leaf->left)
                {
                    temp.emplace_back(leaf->left);
                }
                if(leaf->right)
                {
                    temp.emplace_back(leaf->right);
                }
            }
            re.push_back(r);
            que = temp;
        }

        return re;
    }

// 方法二 使用队列
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        queue<TreeNode *> que;
        que.push(root);
        vector<vector<int>> re;

        while(!que.empty())
        {
            auto que_size = que.size();
            vector<int> r;
            for (auto i = 0; i < que_size; i++)
            {
                TreeNode *temp = que.front();
                que.pop();
                if(temp->left)
                {
                    que.push(temp->left);
                }
                if(temp->right)
                {
                    que.push(temp->right);
                }
                r.push_back(temp->val);
            }
            re.emplace_back(r);
        }
        return re;
    }
};


int main()
{
    TreeNode *root = new TreeNode{3};
    TreeNode *l11 = new TreeNode{9};
    TreeNode *l12 = new TreeNode{20};
    TreeNode *l33 = new TreeNode{15};
    TreeNode *l34 = new TreeNode{7};

    root->left = l11;
    root->right = l12;
    l12->left = l33;
    l12->right = l34;
    Solution s;
    auto re = s.levelOrder1(root);

    for(auto rr:re)
    {
        for(auto r:rr)
        {
            cout << r << ' ';
        }
        cout << '\n';
    }
    return 0;
}
