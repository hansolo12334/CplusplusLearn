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
public:
//不分行从上往下打印二叉树

    //二叉树的层序遍历 BFS 广度优先搜索
    std::vector<int> PrintFromTopToBottom(TreeNode *root)
    {

        std::vector<int> re{};
        std::vector<TreeNode *> vec{};

        vec.push_back(root);
        std::cout << root->val << '\n';
        re.push_back(root->val);
        while (!vec.empty())
        {
            std::vector<TreeNode *> temp;
            for (auto node : vec)
            {
                if (node->left)
                {
                    std::cout << node->left->val << ' ';
                    re.push_back(node->left->val);
                    temp.push_back(node->left);
                }
                if(node->right)
                {
                    std::cout << node->right->val << ' ';
                    re.push_back(node->right->val);
                    temp.push_back(node->right);
                }
            }
            std::cout << '\n';
            vec = temp;
        }
        return re;
    }
};

int main()
{
    TreeNode *root = new TreeNode{1};
    TreeNode *l1 = new TreeNode{2};
    TreeNode *r1 = new TreeNode{3};

    TreeNode *l11 = new TreeNode{4};
    TreeNode *l12 = new TreeNode{5};

    TreeNode *l14 = new TreeNode{6};

    root->left = l1;
    root->right = r1;

    l1->left = l11;
    l1->right = l12;

    r1->right = l14;

    Solution ss;
    auto re=ss.PrintFromTopToBottom(root);
    for(auto r:re)
    {
        std::cout << r << ' ';
    }
    std::cout << '\n';
    return 0;
}
