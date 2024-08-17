#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

struct TreeNode
{
    TreeNode *left{nullptr};
    TreeNode *right{nullptr};
    TreeNode *root{nullptr};
    int val{0};

    TreeNode(int val)
    : val{val}
    {

    }

};



class Solution
{
private:
    TreeNode *re;
    TreeNode *fr = nullptr;

public:
    TreeNode *getBiListN(TreeNode *root) //实际上就是中序遍历
    {
        recur(root);
        while(root && root->left)
        {
            root = root->left;
        }
        return root;
    }


    void recur(TreeNode *node)
    {
        if(!node)
        {
            return;
        }

        recur(node->left);

        node->left = fr;
        if (fr)
        {
            fr->right = node;
        }
        fr = node;

        recur(node->right);
    }
};


int main()
{
    TreeNode *root = new TreeNode{10};

    TreeNode *l11 = new TreeNode{6};
    TreeNode *l12 = new TreeNode{14};


    TreeNode *l21 = new TreeNode{4};
    TreeNode *l22 = new TreeNode{8};
    TreeNode *l23 = new TreeNode{12};
    TreeNode *l24 = new TreeNode{16};


    root->left = l11;
    root->right = l12;

    l11->left = l21;
    l11->right = l22;

    l12->left = l23;
    l12->right = l24;

    Solution ss;

    auto re = ss.getBiListN(root);

    while(re)
    {
        std::cout << re->val << ' ';
        re = re->right;
    }
    std::cout << '\n';
    // while(re->left)
    // {
    //     std::cout << re->val << ' ';
    //     re = re->left;
    // }
    // std::cout << '\n';
    // return 0;
}
