// striver SDE sheet challange Search In BST
// author Vishwas Paikra
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root) {
        if(root->data == x) return true;
        else if(root->data > x) root = root->left;
        else root = root->right;
    }
    return false;
}
