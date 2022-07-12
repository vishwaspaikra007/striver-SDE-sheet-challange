// striver SDE sheet challange Postorder Traversal
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
    TreeNode *temp = root;
    pot(ans, root->left);
    pot(ans, root->right);
    ans.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    pot(ans, root);
    return ans;
}

// using stsck

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> stk;
    while(!stk.empty() || root) {
        if(root) {
            stk.push(root);
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            if(!stk.empty() && stk.top() == root)
                root = root->right;
            else {
                ans.push_back(root->data);
                root = NULL;
            }
        }
    }
    return ans;
}
