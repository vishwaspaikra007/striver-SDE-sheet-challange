// striver SDE sheet challange Partial BST
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
bool chk(BinaryTreeNode<int> *root, int mini, int maxi) {
    if(!root) return true;
    if(root->data < mini || maxi < root->data) return false;
    return chk(root->left, mini, root->data) && chk(root->right, root->data, maxi);
}
bool validateBST(BinaryTreeNode<int> *root) {
   return chk(root, INT_MIN, INT_MAX);
}
