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
    vector<vector<int>> decorateRecord(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        queue<pair<TreeNode *, int>> que;
        vector<vector<int>> re;
        vector<int> temp{root->val};
        re.push_back(temp);
        temp.clear();
        que.push({root,0});
        int floor{0};
        int floorNow{1};
        while (!que.empty())
        {

            if(que.front().first->left)
            {
                temp.push_back(que.front().first->left->val);
                que.push({que.front().first->left, floor+1});
            }
            if(que.front().first->right)
            {
                temp.push_back(que.front().first->right->val);
                que.push({que.front().first->right, floor+1});
            }

            que.pop();
            if(!que.empty() && que.front().second!=floor)
            {
                if(!temp.empty())
                {
                    re.push_back(temp);
                    temp.clear();
                }
                floor++;
            }

        }
        return re;
    }

//解法二
    vector<vector<int>> decorateRecord1(TreeNode* root) {
        vector<vector<int>> re;
        queue<TreeNode *> que;

        if(root)
        {
            que.push(root);
        }

        while(!que.empty())
        {
            vector<int> temp;
            int nowQueSize = que.size();
            //nowQueSize一定是当前层的节点数

            // for (int i = 0; i < nowQueSize; i++)//遍历当前层所有节点
            for (int i = que.size(); i >0; i--)
            {
                root = que.front();
                temp.push_back(root->val);
                que.pop();

                if(root->left)
                {
                    que.push(root->left);
                }
                if(root->right)
                {
                    que.push(root->right);
                }
            }
            re.push_back(temp);
        }
        return re;
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
    vector<vector<int>> re = s.decorateRecord1(root);
    for(auto rr:re)
    {
        for(int r:rr)
        {
            cout << r << ' ';
        }
        cout << '\n';
    }

    return 0;
}
