// striver SDE sheet challange Floor in BST
// author Vishwas Paikra
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int parent = -1;
    while(root && parent != X) {
        if(root->val > X)
            root = root->left;
        else {
            parent = root->val;
            root = root->right;
        }
    }
    return parent;
}
