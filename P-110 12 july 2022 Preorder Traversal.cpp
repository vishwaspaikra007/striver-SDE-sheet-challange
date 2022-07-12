// striver SDE sheet challange Preorder Traversal
// author Vishwas Paikra
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void pot(vector<int> &ans, TreeNode *root) {
    if(!root) return;
    ans.push_back(root->data);
    pot(ans, root->left);
    pot(ans, root->right);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    pot(ans, root);
    return ans;
}

// using stack

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> stk;
    while(!stk.empty() || root) {
        if(root) {
            ans.push_back(root->data);
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            root = root->right;
        }
    }
    return ans;
}
