// striver SDE sheet challange Flatten Binary Tree to Linked List
// author Vishwas Paikra
/************************************************************

    Following is the TreeNode class structure.

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
TreeNode<int> *flattenIt(TreeNode<int> *head, TreeNode<int> *root) {
    if(!root) return head;
    head->right = new TreeNode<int>(root->data);
    head = flattenIt(head->right, root->left);
    head = flattenIt(head, root->right);
    return head;
} 
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *head = new TreeNode<int>(-1), *curr = head;
    flattenIt(curr, root);
    return head->right;
}
