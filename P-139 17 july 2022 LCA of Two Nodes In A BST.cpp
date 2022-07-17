// striver SDE sheet challange LCA of Two Nodes In A BST
// author Vishwas Paikra
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(!root) return root;
    if(P->data < root->data && Q->data < root->data)
        return LCAinaBST(root->left, P, Q);
    if(P->data > root->data && Q->data > root->data)
        return LCAinaBST(root->right, P, Q);
    return root;
}
