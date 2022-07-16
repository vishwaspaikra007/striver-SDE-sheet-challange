// striver SDE sheet challange Convert Sorted Array to BST
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
TreeNode<int>* bbst(vector<int> &arr, int start, int end) {
    if(start > end) return NULL;
    int mid = start + (end-start)/2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = bbst(arr, start, mid-1);
    root->right = bbst(arr, mid+1, end);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return bbst(arr, 0, n-1);
}
