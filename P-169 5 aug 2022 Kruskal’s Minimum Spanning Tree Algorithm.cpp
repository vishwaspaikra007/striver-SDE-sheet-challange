// striver SDE sheet challange Kruskal’s Minimum Spanning Tree Algorithm
// author Vishwas Paikra
#include<bits/stdc++.h>
int comp(vector<int> &a, vector<int> &b) {
    return a[2] <= b[2];
}
int getParent(int child,  vector<int> &parent) {
    int val = child;
    while(parent[child] != child)
        child = parent[child];
    parent[val] = child;
    return child;
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	vector<int> parent(n+1);
    int total_weight = 0;
    for(int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    sort(begin(graph), end(graph), comp);
    for(auto &vec : graph) {
        if(getParent(vec[0], parent) != getParent(vec[1], parent)) {
            total_weight += vec[2]; 
            parent[max(parent[vec[0]], parent[vec[1]])] = min(parent[vec[0]], parent[vec[1]]);
        }
    }
    return total_weight;
}
