// striver SDE sheet challange Boundary Traversal of Binary Tree
// author Vishwas Paikra
/************************************************************

    Following is the Binary Tree node structure:
    
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
void addLeftBoundary(vector<int> &ans, TreeNode<int> *root) {
    if(!root || (root && !root->left && !root->right)) return;
    
    ans.push_back(root->data);
    addLeftBoundary(ans, root->left ? root->left : root->right);
}

void addLeafNodes(vector<int> &ans, TreeNode<int> *root) {
    if(!root) return;
    if(!root->left && !root->right)
        ans.push_back(root->data);
    addLeafNodes(ans, root->left);
    addLeafNodes(ans, root->right);
}

void addRightBoundary(vector<int> &ans, TreeNode<int> *root) {
    if(!root || (root && !root->left && !root->right)) return;
    
    addRightBoundary(ans, root->right ? root->right : root->left);
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root->left || root->right) ans.push_back(root->data);
    addLeftBoundary(ans, root->left);
    addLeafNodes(ans, root);
    addRightBoundary(ans, root->right);
    return ans;
}
