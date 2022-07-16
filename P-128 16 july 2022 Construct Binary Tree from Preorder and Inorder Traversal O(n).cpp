// striver SDE sheet challange Construct Binary Tree from Preorder and Inorder Traversal O(n)
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
public:
    unordered_map<int, int> hash;
    int preOrderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; ++i)
            hash[inorder[i]] = i;
        preOrderIndex = 0;
        return createTree(0, n-1, preorder);
    }
    TreeNode *createTree(int start, int end, vector<int> &preorder) {
        if(start > end) return NULL;
        
        TreeNode *root = new TreeNode(preorder[preOrderIndex++]);
        
        root->left = createTree(start, hash[root->val]-1, preorder);
        root->right = createTree(hash[root->val]+1, end, preorder);
        
        return root;
    }
};
