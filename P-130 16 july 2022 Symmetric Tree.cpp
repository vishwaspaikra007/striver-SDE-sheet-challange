// striver SDE sheet challange Symmetric Tree
// author Vishwas Paikra
/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
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
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool chk(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if((root1 && root2) || (!root1 && !root2)) {
        if(!root1) return true;
        if(root1->data != root2->data) return false;
        
        chk(root1->left, root2->right);
        chk(root1->right, root2->left);
    } else return false;
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    return chk(root, root);
}
