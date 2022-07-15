// striver SDE sheet challange LCA Of Binary Tree
// author Vishwas Paikra
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(!root) return -1;
	stack<pair<TreeNode<int> *, bool>> stk;
    pair<TreeNode<int> *, bool> temp;
    while(!stk.empty() || root) {
        if(root) {
            bool temp = x == root->data || y == root->data;
            stk.emplace(root, temp);
            stk.emplace(root, temp);
            root = root->left;
        } else {
            temp = stk.top();
            stk.pop();
            while(!stk.empty() && temp.first != stk.top().first) {
                if(stk.top().second == true && temp.second == true)
                    return stk.top().first->data;
                stk.top().second |= temp.second;
                temp = stk.top();
                stk.pop();
            }
            if(!stk.empty()) stk.top().second |= temp.second;
            root = temp.first->right;
        }
    }
    return -1;
}
