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
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};


class Solution {
public:
// 方法一 深度优先搜索
    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        if(!root)
        {
            return {};
        }
        vector<vector<int>> re{};
        vector<int> temp{};
        int sums{0};
        dfs_search(re, root, target, sums,temp);
        return re;
    }

    void printVector(vector<int> &temp)
    {
        for(int r:temp)
        {
            cout << r << ' ';
        }
        cout << '\n';
    }
    void dfs_search(vector<vector<int>> &re, TreeNode *leaf,int target,int sums,vector<int> &temp)
    {


        sums += leaf->val;
        temp.push_back(leaf->val);

        if(leaf->left==nullptr &&leaf->right==nullptr && sums==target)
        {
            re.push_back(temp);
            temp.pop_back();
            return;
        }
        if (leaf->left==nullptr &&leaf->right==nullptr && sums!=target)
        {
            temp.pop_back();
            return;
        }


        if(leaf->left)
        {
            dfs_search(re, leaf->left, target, sums,temp);
        }
        if(leaf->right)
        {
            dfs_search(re, leaf->right, target, sums,temp);
        }
        temp.pop_back();

    }
};




int main()
{
    TreeNode *root = new TreeNode{5};

    TreeNode *t11 = new TreeNode{4};
    TreeNode *t12 = new TreeNode{8};

    TreeNode *t21 = new TreeNode{11};
    TreeNode *t22 = new TreeNode{13};
    TreeNode *t23 = new TreeNode{4};

    TreeNode *t31 = new TreeNode{7};
    TreeNode *t32 = new TreeNode{2};
    TreeNode *t33 = new TreeNode{5};
    TreeNode *t34 = new TreeNode{1};

    root->left = t11;
    root->right = t12;

    t11->left = t21;
    t12->left = t22;
    t12->right = t23;

    t21->left = t31;
    t21->right = t32;
    t23->left = t33;
    t23->right = t34;

    Solution s;
    int target{22};
    vector<vector<int>> re = s.pathTarget(root,target);
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
