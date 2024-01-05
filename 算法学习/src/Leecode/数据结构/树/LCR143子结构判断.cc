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
        //特例处理，A为空或B为空时，返回false
        if(A==nullptr || B==nullptr)
        {
            return false;
        }

    // 以节点A为根节点的子树包含树B  树B是树A左子树的子结构         //树B是树A右子树的子结构
        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }


    // isSubStructure 作用 : 遍历树A中的每个节点
    // recur          作用:  判断树A 中以node为根节点的子树是否包含 树 B


private :
    bool recur(TreeNode *A,TreeNode *B)
    {
        if(B==nullptr) //当节点B为空，说明树B已经完成匹配，此时返回true
        {
            return true;
        }
        if(A==nullptr || A->val!=B->val) //当A节点为空，说明此时已经越过A的叶节点，即匹配失败，返回false
                                        // 如果 A和B的值不同，也说明匹配失败，返回false
        {
            return false;
        }
                //判断A和B的左子树是否相同     //判断A和B的右子树是否相同
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
