// striver SDE sheet challange Pair Sum in BST
// author Vishwas Paikra
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    stack<BinaryTreeNode<int> *> left, right;
    BinaryTreeNode<int> *root1 = root, *root2 = root;
    while(root1) {
        left.push(root1);
        root1 = root1->left;
    }
    while(root2) {
        right.push(root2);
        root2 = root2->right;
    }
    while(!left.empty() && !right.empty() && left.top() != right.top()) {
        root1 = left.top();
        root2 = right.top();
        int sum = root1->data + root2->data;
        if(sum == k) return true;
        else if(sum < k) {
            left.pop();
            root1 = root1->right;
            while(root1) {
                left.push(root1);
                root1 = root1->left;
            }
        } else {
            right.pop();
            root2 = root2->left;
            while(root2) {
                right.push(root2);
                root2 = root2->right;
            }
        }
    }
    return false;
}
