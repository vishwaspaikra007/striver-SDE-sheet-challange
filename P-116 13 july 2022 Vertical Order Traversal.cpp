// striver SDE sheet challange Vertical Order Traversal
// author Vishwas Paikra
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    unordered_map<int, vector<int>> hash;
    queue<pair<TreeNode<int> *, int>> stk;
    stk.emplace(root, 0);
    int len = stk.size(), mini = 1, maxi = -1, pos;
    while(len) {
        while(len--) {
            root = stk.front().first;
            pos = stk.front().second;
            stk.pop();
            hash[pos].push_back(root->data);
            mini = min(mini, pos);
            maxi = max(maxi, pos);
            if(root->left) stk.emplace(root->left, pos-1);
            if(root->right) stk.emplace(root->right, pos+1);
        }
        len = stk.size();
    }
    for(int i = mini; i <= maxi; ++i) {
        for(int x : hash[i])
            ans.push_back(x);
    }
    return ans;
}
