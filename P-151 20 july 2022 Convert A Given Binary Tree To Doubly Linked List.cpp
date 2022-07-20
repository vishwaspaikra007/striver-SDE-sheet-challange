// striver SDE sheet challange Convert A Given Binary Tree To Doubly Linked List
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
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head = new BinaryTreeNode<int>(-1), *curr = head ;
    stack<BinaryTreeNode<int>*> stk;
    while(!stk.empty() || root) {
        if(root) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(root->data);
            temp->left = head;
            head->right = temp;
            head = head->right;
            root = root->right;
        }
    }
    curr = curr->right;
    curr->left = NULL;
    return curr;
}
