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
vector<int> bottomView(BinaryTreeNode<int> * root){
    unordered_map<int, int> hash;
    vector<int> ans;
    queue<pair<BinaryTreeNode<int> *, int >> stk;
    stk.emplace(root, 0);
    int mini = 0, maxi = 0, pos;
    int len = stk.size();
    while(len) {
        while(len--) {
            root = stk.front().first;
            pos = stk.front().second; 
            stk.pop();
            mini = min(mini, pos);
            maxi = max(maxi, pos);
            hash[pos] = root->data;
            if(root->left) stk.emplace(root->left, pos-1);
            if(root->right) stk.emplace(root->right, pos+1);
        }
        len = stk.size();
    }
    for(int i = mini; i <= maxi; ++i)
        ans.push_back(hash[i]);
    return ans;
}
