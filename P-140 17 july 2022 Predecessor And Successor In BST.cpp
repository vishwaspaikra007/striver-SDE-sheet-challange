// striver SDE sheet challange Predecessor And Successor In BST
// author Vishwas Paikra
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int rightCorner(BinaryTreeNode<int>* root) {
    while(root->right) root = root->right;
    return root->data;
}
int leftCorner(BinaryTreeNode<int>* root) {
    while(root->left) root = root->left;
    return root->data;
}
pair<int,int> dfs(BinaryTreeNode<int>* root, int child, int parent, int key) {
    if(root->data == key) {
        int pre = root->left ? rightCorner(root->left) : child;
        int suc = root->right ? leftCorner(root->right) : parent;
        return {pre, suc};
    } else {
        if(key < root->data)
            return dfs(root->left, child, root->data, key);
        else
            return dfs(root->right, root->data, parent, key);
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    return dfs(root, -1, -1, key);
}
