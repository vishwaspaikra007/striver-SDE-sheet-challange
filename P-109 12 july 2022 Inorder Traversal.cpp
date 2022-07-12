// striver SDE sheet challange Inorder Traversal
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
void iot(TreeNode *root, vector<int> &ans) {
    if(!root) return;
    iot(root->left, ans);
    ans.push_back(root->data);
    iot(root->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    iot(root, ans);
    return ans;
}

// using stack

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> stk;
    while(!stk.empty() || root) {
        if(root) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            ans.push_back(root->data);
            root = root->right;
        }
    }
    return ans;
}
