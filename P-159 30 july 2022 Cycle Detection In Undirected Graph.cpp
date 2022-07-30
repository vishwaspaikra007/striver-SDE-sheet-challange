// striver SDE sheet challange Cycle Detection In Undirected Graph
// author Vishwas Paikra
#include<bits/stdc++.h>
bool dfs(unordered_map<int, vector<int>> &g, unordered_map<int, bool> &chk, int child, int parent) {
    for(int node : g[child]) {
        if(chk[node] && parent != node) return false;
        if(!chk[node]) {
            chk[node] = true;
            if(dfs(g, chk, node, child) == false)
                return false;
        }
    }
    return true;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> chk;
    for(auto &vec : edges) {
        g[vec[0]].push_back(vec[1]);
        g[vec[1]].push_back(vec[0]);
    }
    for(int i = 1; i <= n; ++i) {
        if(!chk[i]) {
            chk[i] = true;
            if(dfs(g, chk, i, 0) == false) 
                return "Yes";
        }
    }
    return "No";
}
