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
//方法一 迭代
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        stk.push(root);
        vector<int> re{};
        while(!stk.empty())
        {
            TreeNode *temp = stk.top();
            stk.pop();
            if (temp == nullptr)
            {
                break;
            }

            re.push_back(temp->val);
            //前序遍历 就先把右子树入栈 这样 之后最先出栈的一定是 左子树
            if(temp->right)
            {
                stk.push(temp->right);
            }
            if(temp->left)
            {
                stk.push(temp->left);
            }
        }
        return re;
    }

    //方法二 递归
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> re;
        preorder(root, re);
        return re;
    }
    void preorder(TreeNode *root,vector<int> &re)
    {
        if(root==nullptr)
        {
            return;
        }
        re.push_back(root->val);
        preorder(root->left, re);
        preorder(root->right, re);
    }

    //方法三 Morris遍历
     vector<int> preorderTraversal2(TreeNode* root) {
         vector<int> re;
         if(root==nullptr)
         {
             return re;
         }

         TreeNode *p1 = root;
         TreeNode *p2 = nullptr;

         while(p1!=nullptr)
         {
            p2 = p1->left;
            if(p2!=nullptr)
            {
                while(p2->right!=nullptr && p2->right!=p1)
                {
                    p2 = p2->right;
                }
                if(p2->right==nullptr)
                {
                    re.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
                else
                {
                    p2->right = nullptr;
                }
            }
            else
            {
                re.emplace_back(p1->val);
            }
            p1 = p1->right;
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
    l12->left = l31;
    Solution s;
    vector<int> re = s.preorderTraversal2(root);
    for(int r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
