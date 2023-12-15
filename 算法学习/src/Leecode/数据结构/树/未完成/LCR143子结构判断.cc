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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr || B==nullptr)
        {
            return false;
        }
        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }


private :
    bool recur(TreeNode *A,TreeNode *B)
    {
        if(B==nullptr)
        {
            return true;
        }
        if(A==nullptr || A->val!=B->val)
        {
            return false;
        }

        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};

int main()
{
    TreeNode *root1 = new TreeNode{1};
    TreeNode *l11 = new TreeNode{7};
    TreeNode *l12 = new TreeNode{5};
    TreeNode *l21 = new TreeNode{6};
    TreeNode *l31 = new TreeNode{1};

    root1->left = l11;
    root1->right = l12;
    l11->left = l21;
    l21->left = l31;

    TreeNode *root2 = new TreeNode{6};
    TreeNode *t11 = new TreeNode{1};
    root2->left = t11;

    Solution s;
    std::cout << s.isSubStructure(root1, root2) << '\n';
    return 0;
}
