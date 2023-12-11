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
        queue<TreeNode *> que;
        vector<vector<int>> re;
        int reverseLeftRight{-1};
        if (root)
        {
            que.push(root);
        }
        while(!que.empty())
        {
            vector<int> temp;
            for (int i = que.size(); i > 0;i--)
            {
                root = que.front();
                que.pop();
                temp.push_back(root->val);
                if (root->left)
                {
                    que.push(root->left);
                }
                    if (root->right)
                {
                    que.push(root->right);
                }
            }
            if(reverseLeftRight>0)
            {
                reverseTemp(temp);
            }
            re.push_back(temp);
            reverseLeftRight = -reverseLeftRight;
        }


        return re;
    }

    void reverseTemp(vector<int> &temp)
    {
        int fp{0};
        size_t ep{temp.size() - 1};
        while(fp<ep)
        {
            swap(temp[fp], temp[ep]);
            fp++;
            ep--;
        }
    }



    vector<vector<int>> decorateRecord1(TreeNode* root) {
        deque<TreeNode *> que;

        vector<vector<int>> re;
        int reverseLeftRight{-1};
        if (root)
        {
            que.push_back(root);
        }
        while(!que.empty())
        {
            vector<int> temp;
            for (int i = que.size(); i > 0; i--)
            {
                if(reverseLeftRight>0)
                {
                    root = que.front();
                    temp.push_back(root->val);
                    que.pop_front();
                    if (root->right)
                    {
                        que.push_back(root->right);
                    }
                    if(root->left)
                    {
                        que.push_back(root->left);
                    }
                }
                else
                {
                    root = que.back();
                    que.pop_back();
                    temp.push_back(root->val);
                    if(root->left)
                    {
                        que.push_front(root->left);
                    }
                    if(root->right)
                    {
                        que.push_front(root->right);
                    }
                }

            }


            re.push_back(temp);
            reverseLeftRight = -reverseLeftRight;
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
