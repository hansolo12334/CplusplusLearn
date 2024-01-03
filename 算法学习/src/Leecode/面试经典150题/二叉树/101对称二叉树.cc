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
//广度优先搜索
     bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> vec{root};
        while(!vec.empty()){
            vector<TreeNode *> temp;

            for (int i = 0; i < vec.size(); i++)
            {
                if(vec[i] && vec[i]->left){
                    temp.push_back(vec[i]->left);
                }
               else if(vec[i]){
                    temp.push_back(nullptr);
                }
                if(vec[i] && vec[i]->right){
                    temp.push_back(vec[i]->right);
                }
               else if(vec[i]){
                    temp.push_back(nullptr);
                }
            }
            int j = temp.size() - 1;
            int i = 0;
            while (i<j){
                if(temp[i]&&temp[j] &&temp[i]->val!=temp[j]->val)
                {
                    return false;
                }
                 if((temp[i]==nullptr) ^ (temp[j]==nullptr)){
                    return false;
                }
                i++;
                j--;
            }
            vec = temp;
        }
        return true;
    }

    //官方方法 递归
    bool check(TreeNode *p,TreeNode *q){
        if(!p && !q ){
            return true;
        }
        if(!p|| !q){
            return false;
        }
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric1(TreeNode* root) {
        return check(root, root);
    }

    //官方方法 迭代
    bool check2(TreeNode *u,TreeNode *v){
        queue<TreeNode *> q;
        q.push(u);
        q.push(v);
        while(!q.empty()){
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if(!u&&!v){//两个都到了末端
                continue;
            }
            if(!u || !v || (u->val!= v->val)){
                return false;
            }
            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }

        return true;
    }
    bool isSymmetric2(TreeNode *root){
        return check2(root, root);
    }
};


int main()
{
    TreeNode *root = new TreeNode{1};
    TreeNode *l11 = new TreeNode{2};
    TreeNode *l12 = new TreeNode{2};
    TreeNode *l21 = new TreeNode{3};
    TreeNode *l22 = new TreeNode{4};
    TreeNode *l23 = new TreeNode{4};
    TreeNode *l24 = new TreeNode{3};

    TreeNode *l33 = new TreeNode{8};
    TreeNode *l34 = new TreeNode{9};
    TreeNode *l37 = new TreeNode{9};
    TreeNode *l38 = new TreeNode{8};

    root->left = l11;
    root->right = l12;
    l11->left = l21;
    l11->right = l22;
    l12->left = l23;
    l12->right = l24;

    l22->left = l33;
    l22->right = l34;
    l24->left = l37;
    l24->right = l38;

    Solution s;
    cout << s.isSymmetric2(root) << '\n';
    return 0;
}
