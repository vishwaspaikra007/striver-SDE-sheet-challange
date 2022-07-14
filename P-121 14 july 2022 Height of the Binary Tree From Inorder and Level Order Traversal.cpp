// striver SDE sheet challange Height of the Binary Tree From Inorder and Level Order Traversal
// author Vishwas Paikra
#include<bits/stdc++.h>
class Node {
    public:
    int height;
    int leftIndex, rightIndex;
    Node(int data, int l, int r) {
        height = data;
        leftIndex = l;
        rightIndex = r;
    }
};
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    unordered_map<int, int> idxs;
    queue<Node *> stk;
    Node *root = new Node(0, 0, N-1);
    stk.push(root);
    for(int i = 0; i < N; ++i) {
        idxs[inorder[i]] = i;
    }
    int maxi = 0;
    for(int i = 0; i < N; ++i) {
        int curr = levelOrder[i];
        root = stk.front();
        stk.pop();
        if(idxs[curr] > root->leftIndex) {
            Node *temp = new Node(root->height+1, root->leftIndex, idxs[curr]-1);
            maxi = max(maxi, root->height+1);
            stk.push(temp);
        }
        if(idxs[curr] < root->rightIndex) {
            Node *temp = new Node(root->height+1, idxs[curr]+1, root->rightIndex);
            maxi = max(maxi, root->height+1);
            stk.push(temp);
        }
    }
    return maxi;
}
