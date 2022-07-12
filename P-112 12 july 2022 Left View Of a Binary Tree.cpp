// striver SDE sheet challange Left View Of a Binary Tree
// author Vishwas Paikra
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void iot(TreeNode<int> *root, vector<int> &ans, int height, int &maxi) {
    if(!root) return;
    if(height >= maxi) {
        ans.push_back(root->data);
        ++maxi;
    }
    iot(root->left, ans, height+1, maxi);
    iot(root->right, ans, height+1, maxi);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    int cnt = 0, maxi = 0;
    vector<int> ans;
    iot(root, ans, 0, maxi);
    return ans;
}
