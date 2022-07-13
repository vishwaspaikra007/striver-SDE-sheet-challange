// striver SDE sheet challange Bottom View Of Binary Tree
// author Vishwas Paikra
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
void traverse(unordered_map<int, pair<int, int>> &hash, unordered_map<int, bool> &chk, BinaryTreeNode<int> * root, int pos, int depth, int &mini, int &maxi) {
    if(!root) return;
    if(chk[pos]) {
        if(hash[pos].second <= depth)
            hash[pos] = {root->data, depth};
    } else {
        hash[pos] = {root->data, depth};
        chk[pos] = true;
    }
    mini = min(mini, pos);
    maxi = max(maxi, pos);
    traverse(hash, chk, root->left, pos-1, depth+1, mini, maxi);
    traverse(hash, chk, root->right, pos+1, depth+1, mini, maxi);
}
vector<int> bottomView(BinaryTreeNode<int> * root){
    unordered_map<int, pair<int, int>> hash;
    unordered_map<int, bool> chk;
    vector<int> ans;
    int mini = 0, maxi = 0;
    traverse(hash, chk, root, 0, 0, mini, maxi);
    for(int i = mini; i <= maxi; ++i)
        ans.push_back(hash[i].first);
    return ans;
}
