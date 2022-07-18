// striver SDE sheet challange Ceil from BST
// author Vishwas Paikra
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    int parent = -1;
    while(node && parent != x) {
        if(node->data >= x) {
            parent = node->data;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return parent;
}
