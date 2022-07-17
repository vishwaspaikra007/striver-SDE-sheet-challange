// striver SDE sheet challange maximum-subarray-sum
// author Vishwas Paikra
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int idx, n;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx = 0;
        n = preorder.size();
        return createBST(preorder, INT_MAX);
    }
    TreeNode* createBST(vector<int>& preorder, int upper_bound) {
        
        if(idx >= n || preorder[idx] > upper_bound) return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        
        root->left = createBST(preorder, root->val);
        root->right = createBST(preorder, upper_bound);
        
        return root;
    }
};
