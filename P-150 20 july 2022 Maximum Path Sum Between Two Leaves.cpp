// striver SDE sheet challange Maximum Path Sum Between Two Leaves
// author Vishwas Paikra
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
long long int dfs(TreeNode<int> *root, long long int &ans) {
    if(!root) {
        return 0;
    }
    long long int l_val = dfs(root->left, ans);
    long long int r_val = dfs(root->right, ans);
    ans = max(ans, root->val + l_val + r_val);
    return root->val + max(l_val, r_val);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root) return -1;
    if(!root->left || !root->right) return -1;
    long long int ans = 0;
    dfs(root, ans);
    return ans;
}
