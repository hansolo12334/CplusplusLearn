#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


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
// BFS 广度优先搜索
    TreeNode* invertTree(TreeNode* root) {
        vector<TreeNode *> vec{root};
        while(!vec.empty()){
            vector<TreeNode *> temp;
            for(TreeNode* node:vec){
                if(node && node->left){
                    temp.push_back(node->left);
                }
                else if(node&&  ((node->left==nullptr) ^ (node->right==nullptr))){
                    temp.push_back(nullptr);
                }
                if(node && node->right){
                    temp.push_back(node->right);
                }
                else if(node&&  ((node->left==nullptr) ^ (node->right==nullptr))){
                    temp.push_back(nullptr);
                }
                if(node){
                    TreeNode *tt = node->right;
                    node->right = node->left;
                    node->left = tt;
                }
            }
            vec = temp;
        }
        return root;
    }

//官方解法 ：  递归
    TreeNode* invertTree1(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        TreeNode *left = invertTree1(root->left);
        TreeNode *right = invertTree1(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};


int main()
{
    TreeNode *root = new TreeNode{4};
    TreeNode *t11 = new TreeNode{2};
    TreeNode *t12 = new TreeNode{7};
    TreeNode *t21 = new TreeNode{1};
    TreeNode *t22 = new TreeNode{3};
    TreeNode *t23 = new TreeNode{6};
    TreeNode *t24 = new TreeNode{9};

    root->left = t11;
    root->right = t12;
    t11->left = t21;
    t11->right = t22;
    t12->left = t23;
    t12->right = t24;

    Solution s;
    TreeNode *re = s.invertTree(root);

    vector<TreeNode *> vec{re};
    while(!vec.empty()){
        vector<TreeNode *> temp{};
        for(TreeNode* node: vec){
            cout << node->val << ' ';
            if(node->left){
                temp.push_back(node->left);
            }
            if(node->right){
                temp.push_back(node->right);
            }
        }
        cout << '\n';
        vec = temp;
    }
}
