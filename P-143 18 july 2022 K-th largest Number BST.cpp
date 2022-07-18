// striver SDE sheet challange K-th largest Number BST
// author Vishwas Paikra
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    stack<TreeNode<int> *> stk;
    while(!stk.empty() || root) {
        if(root) {
            stk.push(root);
            root = root->right;
        } else {
            root = stk.top();
            stk.pop();
            if(--k == 0) return root->data;
            root = root->left;
        }
    }
    return -1;
}
