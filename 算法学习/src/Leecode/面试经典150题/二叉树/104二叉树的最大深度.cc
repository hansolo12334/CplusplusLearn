#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include<queue>
#include <limits.h>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <unordered_set>


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
//层序遍历 广度优先搜索 BFS
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        vector<TreeNode *> que;
        que.push_back(root);
        int re = 0;
        while (!que.empty())
        {
            vector<TreeNode *> temp{};
            for(TreeNode * t: que){
                if(t->left){
                    temp.push_back(t->left);
                }
                if(t->right){
                    temp.push_back(t->right);
                }
            }
            re++;
            que = temp;
        }
        return re;
    }
// 深度优先搜索 DFS
    int maxDepth1(TreeNode* root) {
        return recur(root);
    }
    int recur(TreeNode *node){
        if(node==nullptr){
            return 0;
        }
        else{
            int deepl = recur(node->left);
            int deepr = recur(node->right);
            if(deepl>deepr){
                return deepl + 1;
            }
            else{
                return deepr + 1;
            }
        }
    }
};


int main()
{
    TreeNode *root = new TreeNode{3};
    TreeNode *l11 = new TreeNode{9};
    TreeNode *l12 = new TreeNode{20};
    TreeNode *l31 = new TreeNode{15};
    TreeNode *l32 = new TreeNode{7};

    root->left = l11;
    root->right = l12;
    l12->left = l31;
    l12->right = l32;

    Solution s;
    cout << s.maxDepth1(root) << '\n';
    return 0;
}
