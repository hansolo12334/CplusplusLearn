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
//方法一 递归
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        postorder(root, re);
        return re;
    }

    void postorder(TreeNode *root,vector<int> &re)
    {
        if(root==nullptr)
        {
            return;
        }

        postorder(root->left, re);
        postorder(root->right, re);

        re.push_back(root->val);
    }


    //方法二 迭代
    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> re;
        stack<TreeNode *> stk;

        TreeNode *preNode = nullptr;

        //主要思想：
        //由于在某颗子树访问完成以后，接着就要回溯到其父节点去
        //因此可以用preNode来记录访问历史，在回溯到父节点时，可以由此来判断，上一个访问的节点是否为右子树
        while (root || !stk.empty())
        {

            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            //从栈中弹出的元素，左子树一定是访问完了的
            root = stk.top();
            stk.pop();
            //现在需要确定的是是否有右子树，或者右子树是否访问过
            //如果没有右子树，或者右子树访问完了，也就是上一个访问的节点是右子节点时
            //说明可以访问当前节点
            if(root->right==nullptr || root->right==preNode)
            {
                re.push_back(root->val);
                //更新历史访问记录，这样回溯的时候父节点可以由此判断右子树是否访问完成
                preNode = root;
                root = nullptr;
            }
            else
            {  //如果右子树没有被访问，那么将当前节点压栈，访问右子树
                stk.push(root);
                root = root->right;
            }
        }
        return re;
    }
};




int main()
{
    TreeNode *root = new TreeNode{1};
    TreeNode *l11 = new TreeNode{2};
    TreeNode *l12 = new TreeNode{3};
    TreeNode *l21 = new TreeNode{4};
    TreeNode *l22 = new TreeNode{5};

    root->left = l11;
    root->right = l12;
    l11->left = l21;
    l11->right = l22;

    Solution s;
    vector<int> re = s.postorderTraversal1(root);

    for(auto r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';

    return 0;
}
