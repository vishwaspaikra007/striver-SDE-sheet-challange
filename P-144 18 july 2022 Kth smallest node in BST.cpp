// striver SDE sheet challange Kth smallest node in BST
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
int kthSmallest(TreeNode<int> *root, int k)
{
	stack<TreeNode<int> *> stk;
    while(!stk.empty() || root) {
        if(root) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            if(--k == 0) return root->data;
            stk.pop();
            root = root->right;
        }
    }
    return -1;
}
