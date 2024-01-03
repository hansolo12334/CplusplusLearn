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

class Solution
{
public:

//广度优先搜索 BFS
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(p && q&& p->val!=q->val){
            return false;
        }
        vector<TreeNode *> vec1;
        vector<TreeNode *> vec2;
        vec1.push_back(p);
        vec2.push_back(q);

        while (!vec1.empty() && !vec2.empty())
        {
            vector<TreeNode *> temp1;
            vector<TreeNode *> temp2;
            for (int i = 0; i < vec1.size(); i++)
            {
                if (vec1[i] && vec1[i]->left)
                {
                    temp1.push_back(vec1[i]->left);
                }
                else if (vec1[i] && vec1[i]->left == nullptr)
                {
                    temp1.push_back(nullptr);
                }
                if (vec1[i] && vec1[i]->right)
                {
                    temp1.push_back(vec1[i]->right);
                }
                else if (vec1[i] && vec1[i]->right == nullptr)
                {
                    temp1.push_back(nullptr);
                }
            }

            for (int i = 0; i < vec2.size(); i++)
            {
                if (vec2[i] && vec2[i]->left)
                {
                    temp2.push_back(vec2[i]->left);
                }
                else if (vec2[i] && vec2[i]->left == nullptr)
                {
                    temp2.push_back(nullptr);
                }
                if (vec2[i] && vec2[i]->right)
                {
                    temp2.push_back(vec2[i]->right);
                }
                else if (vec2[i] && vec2[i]->right == nullptr)
                {
                    temp2.push_back(nullptr);
                }
            }

            if (temp1.size() != temp2.size())
            {
                return false;
            }
            for (int i = 0; i < temp1.size(); i++)
            {
                if ((temp1[i] == nullptr && temp2[i] != nullptr) || (temp1[i] != nullptr && temp2[i] == nullptr) ||
                    ((temp1[i] != nullptr && temp2[i] != nullptr) && temp1[i]->val != temp2[i]->val))
                {
                    return false;
                }
            }

            vec1 = temp1;
            vec2 = temp2;
        }
        return true;
    }

//广度优先搜索 官方解法
    bool isSameTree1(TreeNode *p, TreeNode *q){
        if(p==nullptr && q==nullptr){
            return true;
        }
        else if(p==nullptr || q==nullptr){
            return false;
        }
        queue<TreeNode *> que1;
        queue<TreeNode *> que2;
        que1.push(p);
        que2.push(q);
        while(!que1.empty() && !que2.empty()){
            TreeNode *temp1 = que1.front();
            TreeNode *temp2 = que2.front();
            que1.pop();
            que2.pop();
            if(temp1->val!=temp2->val){
                return false;
            }
            TreeNode *left1 = temp1->left;
            TreeNode *right1 = temp1->right;
            TreeNode *left2 = temp2->left;
            TreeNode *right2 = temp2->right;
            if( (left1==nullptr && left2!=nullptr) || (left1==nullptr && left2!=nullptr)){
                return false;
            }
            if( (right1==nullptr && right2!=nullptr) || (right1==nullptr && right2!=nullptr)){
                return false;
            }
            if(left1!=nullptr){
                que1.push(left1);
            }
            if(right1!=nullptr){
                que1.push(right1);
            }
            if(left2!=nullptr){
                que2.push(left2);
            }
            if(right2!=nullptr){
                que2.push(right2);
            }
        }

        return que1.empty() && que2.empty();
    }

//方法二 官方 深度优先搜索
    bool isSameTree2(TreeNode *p, TreeNode *q){
        if(p==nullptr && q==nullptr){
            return true;
        }
        else if(p==nullptr || q==nullptr){
            return false;
        }
        else if(p->val!=q->val){
            return false;
        }
        else{
            return isSameTree2(p->left, q->left) && isSameTree2(p->right, q->right);
        }
    }
};


int main()
{
    TreeNode *root1 = new TreeNode{1};
    TreeNode *l11 = new TreeNode{2};
    TreeNode *l12 = new TreeNode{3};

    root1->left = l11;
    root1->right = l12;

    TreeNode *root2 = new TreeNode{1};
    TreeNode *ll11 = new TreeNode{2};
    TreeNode *ll12 = new TreeNode{3};

    root2->left = ll11;
    root2->right = ll12;

    Solution s;
    cout << s.isSameTree2(root1,root2) << '\n';
    return 0;
}
