// striver SDE sheet challange Construct BST from Preorder Traversal
// author Vishwas Paikra
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    TreeNode<int> *head = new TreeNode<int>(-1), *root;
    for(int x : preOrder) {
        root = head;
        while(true) {
            if(root->data > x) {
                if(!root->left) {
                    root->left = new TreeNode<int>(x);
                    break;
                }
                root = root->left;
            } else {
                if(!root->right) {
                    root->right = new TreeNode<int>(x);
                    break;
                }
                root = root->right;
            }
        }
    }
    return head->right;
}
