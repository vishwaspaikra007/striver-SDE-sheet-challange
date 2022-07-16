// striver SDE sheet challange Construct Binary Tree from Inorder and Postorder Traversal
// author Vishwas Paikra
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* convertToTree(int start, int end, vector<int> &postOrder, int &postOrderIndex, unordered_map<int, int> &hash) {
    if(start > end) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(postOrder[postOrderIndex--]);
    
    root->right = convertToTree(hash[root->data]+1, end, postOrder, postOrderIndex, hash);
    root->left = convertToTree(start, hash[root->data]-1, postOrder, postOrderIndex, hash);
    
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    int n = inOrder.size();
	unordered_map<int, int> hash;
    for(int i = 0; i < n; ++i)
        hash[inOrder[i]] = i;
    int postOrderIndex = n-1;
    return convertToTree(0, n-1, postOrder, postOrderIndex, hash);
}
