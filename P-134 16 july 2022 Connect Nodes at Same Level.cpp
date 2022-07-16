// striver SDE sheet challange Connect Nodes at Same Level
// author Vishwas Paikra
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode< int > *> stk;
    stk.push(root);
    stk.push(NULL);
    while(stk.front()) {
        root = stk.front();
        stk.pop();
        root->next = stk.front();
        if(root->left) stk.push(root->left);
        if(root->right) stk.push(root->right);
        if(!stk.front()) {
            stk.pop();
            stk.push(NULL);
        }
    }
}
