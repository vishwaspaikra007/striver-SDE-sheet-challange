// striver SDE sheet challange Is Height Balanced Binary Tree
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
int calc(BinaryTreeNode<int>* root, bool &isBal) {
    if(!root || !isBal) return 0;
    int leftHeight = calc(root->left, isBal);
    int rightHeight = calc(root->right, isBal);
    if(abs(leftHeight - rightHeight) > 1)
        isBal = false;
    return 1 + max(leftHeight, rightHeight);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    bool isBal = true;
    calc(root, isBal);
    return isBal;
}
