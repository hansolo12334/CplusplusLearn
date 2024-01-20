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
//自底向上
    int maxDepth(TreeNode* root) {

        if(root==nullptr)
        {
            return 0;
        }

        int dl=maxDepth(root->left);
        int dr=maxDepth(root->right);

        return max(dl, dr) + 1;
    }

// BFS 广度优先搜索方法
    int maxDepth1(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        vector<TreeNode *> vec{root};
        int depth = 0;
        while(!vec.empty())
        {
            depth++;
            vector<TreeNode *> temp;
            for (auto v : vec)
            {
                if(v->left)
                {
                    temp.push_back(v->left);
                }
                if(v->right)
                {
                    temp.push_back(v->right);
                }

            }
            vec = temp;
        }

        return depth;
    }
};


int main()
{

    TreeNode *root = new TreeNode{3};
    TreeNode *l11 = new TreeNode{9};
    TreeNode *l12 = new TreeNode{20};
    TreeNode *l23 = new TreeNode{15};
    TreeNode *l24 = new TreeNode{7};

    root->left = l11;
    root->right = l12;
    l12->left = l23;
    l12->right = l24;

    Solution s;
    cout << s.maxDepth1(root) << '\n';
    return 0;
}
