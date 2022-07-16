// striver SDE sheet challange Binary Tree Zigzag Traversal
// author Vishwas Paikra
/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/
#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    deque<BinaryTreeNode<int> *> stk;
    if(root) {
        stk.push_back(root);
        ans.push_back(root->data);
    }
    int len = stk.size();
    bool toggle = false;
    while(len) {
        while(len--) {
            if(toggle) {
                root = stk.front();
                stk.pop_front();
            } else {
                root = stk.back();
                stk.pop_back();
            }
            if(toggle) {
                if(root->left) {
                    stk.push_back(root->left);
                    ans.push_back(root->left->data); 
                }
                if(root->right) {
                    stk.push_back(root->right);
                    ans.push_back(root->right->data); 
                }
            } else {
                if(root->right) {
                    stk.push_front(root->right);
                    ans.push_back(root->right->data); 
                }
                if(root->left) {
                    stk.push_front(root->left);
                    ans.push_back(root->left->data); 
                }
            }
        }
        len = stk.size();
        toggle = !toggle;
    }
    return ans;
}
