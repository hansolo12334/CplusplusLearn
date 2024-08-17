#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<math.h>

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
    std::vector<TreeNode*> sort_list;


public:
    Solution()
    {

    }

    TreeNode*  findKMin(TreeNode *root,int k)
    {
        recur(root);

        for(auto r:sort_list){
            std::cout << r->val << ' ';
        }
        std::cout << '\n';
        return sort_list[k-1];
    }

    void recur(TreeNode *node)
    {
        if(!node)
        {
            return;
        }
        sort_list.push_back(node);
        std::sort(sort_list.begin(), sort_list.end(),
        [&](TreeNode *tr1, TreeNode *tr2) {
            return tr1->val < tr2->val;
        });


        recur(node->left);
        recur(node->right);
    }
};


int main()
{
    TreeNode *root = new TreeNode{2};

    TreeNode *l11 = new TreeNode{1};
    TreeNode *l12 = new TreeNode{3};


    root->left = l11;
    root->right = l12;

    int k = 3;

    Solution ss;

    std::cout << ss.findKMin(root,k)->val << '\n';
    return 0;
}
