// striver SDE sheet challange Top View Of Binary Tree
// author Vishwas Paikra
/************************************************************

    Following is the TreeNode class structure:

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
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    unordered_map<int, int> hash;
    queue<pair<TreeNode <int>*, int>> stk;
    vector<int> ans;
    if(root) stk.emplace(root, 0);
    int mini = INT_MAX, maxi = INT_MIN, pos;
    int len = stk.size();
    while(len) {
        while(len--) {
            root = stk.front().first;
            pos = stk.front().second;
            stk.pop();
            mini = min(mini, pos);
            maxi = max(maxi, pos);
            if(!hash[pos])
                hash[pos] = root->val;
            if(root->left) stk.emplace(root->left, pos-1);
            if(root->right) stk.emplace(root->right, pos+1);
        }
        len = stk.size();
    }
    for(int i = mini; i <= maxi; ++i)
        ans.push_back(hash[i]);
    return ans;
}
