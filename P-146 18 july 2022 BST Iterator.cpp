// striver SDE sheet challange BST Iterator
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
class BSTiterator
{
    stack<TreeNode<int> *> stk;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        fillStack(root);
    }

    int next()
    {
        TreeNode<int> *root = stk.top();
        stk.pop();
        int temp = root->data;
        root = root->right;
        fillStack(root);
        return temp;
    }
    
    void fillStack(TreeNode<int> *root) {
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
