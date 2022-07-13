// striver SDE sheet challange Tree Traversals
// author Vishwas Paikra
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h>
void traverse(vector<int> &t1, vector<int> &t2, vector<int> &t3, BinaryTreeNode<int> *root) {
    if(!root) return;
    t2.push_back(root->data);
    traverse(t1, t2, t3, root->left);
    t1.push_back(root->data);
    traverse(t1, t2, t3, root->right);
    t3.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans(3);
    vector<int> t1, t2, t3;
    traverse(t1, t2, t3, root);
    ans[0] = t1;
    ans[1] = t2;
    ans[2] = t3;
    return ans;
}
