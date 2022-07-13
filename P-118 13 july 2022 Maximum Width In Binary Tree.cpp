// striver SDE sheet challange Maximum Width In Binary Tree
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

int getMaxWidth(TreeNode<int> *root)
{
    queue<TreeNode<int> *>stk;
    if(root) stk.push(root);
    int len = stk.size(), maxi = len;
    while(len) {
        while(len--) {
            root = stk.front();
            stk.pop();
            if(root->left) stk.push(root->left);
            if(root->right) stk.push(root->right);
        }
        len = stk.size();
        maxi = max(maxi, len);
    }
    return maxi;
}
