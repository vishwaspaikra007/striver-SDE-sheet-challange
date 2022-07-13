// striver SDE sheet challange Level Order Traversal
// author Vishwas Paikra
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    queue<BinaryTreeNode<int> *> stk;
    if(root) stk.push(root);
    int len = stk.size();
    while(len) {
        while(len--) {
            root = stk.front();
            stk.pop();
            ans.push_back(root->val);
            if(root->left) stk.push(root->left);
            if(root->right) stk.push(root->right);
        }
        len = stk.size();
    }
    return ans;
}
