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
    int pathSum(TreeNode* root, int targetSum) {
        int re=0;

        vector<TreeNode*> vec;
        vec.emplace_back(root);

        while(!vec.empty() &&root!=nullptr)
        {
            vector<TreeNode *> temp;
            for(auto v:vec)
            {
                if(v->left)
                {
                    temp.emplace_back(v->left);
                }
                if(v->right)
                {
                    temp.emplace_back(v->right);
                }
                bool b = recur(v, targetSum);
                if (b|| m_num)
                {
                    re += m_num;
                    m_num = 0;
                }
            }
            vec = temp;
        }
        return re;
    }


    bool recur(TreeNode *root, int targetSum)
    {
        if(root==nullptr)
        {
            if(targetSum==0)
            {
                m_num++;
            }
            return targetSum == 0;
        }
        if(targetSum==0)
        {
            m_num++;
        }

        return recur(root->left, targetSum-root->val)||
        recur(root->right, targetSum-root->val);

    }
private:
    int m_num = 0;
};


int main()
{
    TreeNode *root = new TreeNode{10};

    TreeNode *l11 = new TreeNode{5};
    TreeNode *l12 = new TreeNode{-3};

    TreeNode *l21 = new TreeNode{3};
    TreeNode *l22 = new TreeNode{2};
    TreeNode *l24 = new TreeNode{11};

    TreeNode *l31 = new TreeNode{3};
    TreeNode *l32 = new TreeNode{-2};
    TreeNode *l34 = new TreeNode{1};

    root->left = l11;
    root->right = l12;

    l11->left = l21;
    l11->right = l22;

    l12->right = l24;

    l21->left = l31;
    l21->right = l32;

    l22->right = l34;

    int targetSum = 8;

    Solution s;
    cout << s.pathSum(l11,targetSum) << '\n';
    return 0;
}
