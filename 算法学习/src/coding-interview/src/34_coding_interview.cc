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
    std::vector<std::vector<int>> re;

public:
    Solution()
    {

    }


    void recur(TreeNode *node,int sum,std::vector<int> temp)
    {
        if(!node)
        {
            return;
        }
        sum -= node->val;
        temp.push_back(node->val);
        if( !node->left &&!node->right && sum==0)
        {
            re.push_back(temp);

            return;
        }


        recur(node->left, sum ,temp);
        recur(node->right, sum,temp);

    }

    std::vector<std::vector<int>> getPath(TreeNode *root,int sum)
    {
        std::vector<int> temp{};
        recur(root, sum,temp);
        return re;
    }
};


int main()
{
    TreeNode *root = new TreeNode{5};

    TreeNode *l11 = new TreeNode{4};
    TreeNode *l12 = new TreeNode{6};


    TreeNode *l21 = new TreeNode{12};
    TreeNode *l22 = new TreeNode{13};
    TreeNode *l23 = new TreeNode{6};

    TreeNode *l31 = new TreeNode{9};
    TreeNode *l32 = new TreeNode{1};
    TreeNode *l33 = new TreeNode{5};
    TreeNode *l34 = new TreeNode{1};

    root->left = l11;
    root->right = l12;

    l11->left = l21;
    l12->left = l22;
    l12->right = l23;

    l21->left = l31;
    l21->right = l32;
    l23->left = l33;
    l23->right = l34;

    int num = 22;

    Solution ss;

    auto re = ss.getPath(root,num);

    for(auto rr:re)
    {
        for(auto r:rr)
        {
            std::cout << r << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
