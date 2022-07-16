// striver SDE sheet challange Invert a Binary Tree
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
TreeNode<int> * traverse(TreeNode<int> *root, TreeNode<int> *parent, TreeNode<int> *leaf) {
    if(!root) return NULL;
    if(root->data == leaf->data) {
        root->left = parent;
        return root;
    }
    TreeNode<int> * temp = traverse(root->left, root, leaf);
    if(temp) {
        root->left = parent;
        return temp;
    }
    temp = traverse(root->right, root, leaf);
    if(temp) {
        root->right = root->left;
        root->left = parent;
        return temp;
    } 
    return NULL;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	return traverse(root, NULL, leaf);
}
