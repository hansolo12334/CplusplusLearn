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


//之字形打印二叉树
class Solution
{
public:
    std::vector<std::vector<int>> Print(TreeNode *root)
     {
        std::vector<TreeNode *> vec;
        std::vector<std::vector<int>> re{};

        vec.push_back(root);
        re.push_back({root->val});

        bool reverse = true;
        while (!vec.empty())
        {
            std::vector<TreeNode *> temp;
            std::vector<int> re1;
            for (auto rt : vec)
            {
                if(rt->left){
                    temp.emplace_back(rt->left);
                    re1.push_back(rt->left->val);
                }
                if(rt->right)
                {
                    temp.emplace_back(rt->right);
                    re1.push_back(rt->right->val);
                }
            }
            if(reverse){
                std::reverse(re1.begin(), re1.end());
                reverse = false;
            }
            else{
                reverse = true;
            }
            re.push_back(re1);
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
    auto re=ss.Print(root);
    for(auto r:re)
    {
        for(auto rr:r){
            std::cout << rr << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
