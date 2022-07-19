// striver SDE sheet challange Size of Largest BST in Binary Tree
// author Vishwas Paikra
/************************************************************

    Following is the Binary Tree node structure
    
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
class Node {
    public:
    bool bst;
    int mc;
    int mi;
    int ma;
    Node() {
        bst = true;
        mc = 0;
        mi = INT_MAX;
        ma = INT_MIN;
    }
};
Node dfs(TreeNode<int>* root) {
    if(!root) {
        return Node();
    }
    Node l_node = dfs(root->left);
    Node r_node = dfs(root->right);
    
    Node bst_node;
    if(l_node.bst && r_node.bst && l_node.ma < root->data && root->data < r_node.mi) {
        bst_node.mc = l_node.mc + r_node.mc + 1;
        bst_node.mi = min(root->data, l_node.mi);
        bst_node.ma = max(root->data, r_node.ma);
        return bst_node;
    } else {
        bst_node.bst = false;
        bst_node.mc = max(l_node.mc, r_node.mc);
    }
    
    return bst_node;
    
}
int largestBST(TreeNode<int>* root) 
{   
    return dfs(root).mc;
}
