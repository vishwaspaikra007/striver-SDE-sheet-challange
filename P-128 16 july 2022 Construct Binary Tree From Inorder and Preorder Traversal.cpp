// striver SDE sheet challange Construct Binary Tree From Inorder and Preorder Traversal
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
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = preorder.size();
    unordered_map<int, int> hash;
    for(int i = 0; i < n; ++i) 
        hash[inorder[i]] = i;
    TreeNode<int> *root = new TreeNode<int>(preorder[0]);
	for(int i = 1; i < n; ++i) {
        int x = preorder[i];
        TreeNode<int> *curr = root;
        while(curr) {
            if(hash[curr->data] > hash[x]) {
                if(curr->left == NULL) {
                    curr->left = new TreeNode<int>(x);
                    break;
                }
                curr = curr->left;
            } else {
                if(curr->right == NULL) {
                    curr->right = new TreeNode<int>(x);
                    break;
                }
                curr = curr->right;
            }
        }
    }
    return root;
}
