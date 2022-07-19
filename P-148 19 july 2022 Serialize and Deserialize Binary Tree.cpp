// striver SDE sheet challange Serialize and Deserialize Binary Tree
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
#include<bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
    queue<TreeNode<int> *> stk;
    string ans = "";
    if(root) {
        stk.push(root);
        ans += to_string(root->data);
    }
    int len = stk.size();
    ans += " ";
    
    while(len) {
        while(len--) {
            root = stk.front();
            stk.pop();
            if(root->left) {
                stk.push(root->left);
                ans += to_string(root->left->data) + " ";
            }
            else ans += "-1 ";
            if(root->right) {
                stk.push(root->right);
                ans += to_string(root->right->data) + " ";
            }
            else ans += "-1 ";
        }
        len = stk.size();
    }
    
    ans.pop_back();
    return ans;
}
TreeNode<int>* deserializeTree(string &serialized)
{
    vector<int> vec;
    int i = 0, n = serialized.size();
    for(; i < n; ++i) {
        if(serialized[i] == '-') {
            vec.push_back(-1);
            ++i;
            continue;
        }
        if(serialized[i] == ' ') continue;
        int num = 0;
        while(i < n && serialized[i] != ' ') {
            num = num*10 + (serialized[i++]-48);
        }
        vec.push_back(num);
    }
    TreeNode<int>* root = NULL, *head;
    queue<TreeNode<int> *> stk;
    if(!vec.empty()) {
        root = new TreeNode<int>(vec[0]);
        stk.push(root);
    }
    head = root;
    i = 0;
    while(!stk.empty()) {
        root = stk.front();
        stk.pop();
        if(vec[++i] != -1) {
            root->left = new TreeNode<int>(vec[i]);
            stk.push(root->left);
        } else {
            root->left = NULL;
        }
        if(vec[++i] != -1) {
            root->right = new TreeNode<int>(vec[i]);
            stk.push(root->right);
        } else {
            root->right = NULL;
        }
    }
    return head;
}



