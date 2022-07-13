// striver SDE sheet challange Diameter Of Binary Tree
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
int traverse(TreeNode<int> *root, int &maxi) {
    if(!root) return 0;
    int left = traverse(root->left, maxi);
    int right = traverse(root->right, maxi);
    maxi = max(maxi, left + right);
    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxi = 0;
	traverse(root, maxi);
    return maxi;
}
