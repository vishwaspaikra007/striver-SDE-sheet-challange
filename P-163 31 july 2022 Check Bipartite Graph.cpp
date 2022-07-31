// striver SDE sheet challange Check Bipartite Graph
// author Vishwas Paikra
#include<bits/stdc++.h>
bool dfs(vector<vector<int>> &g, vector<int> &color, int curr_color, int idx) {
    for(int i : g[idx]) {
        if(color[i] == 0) {
            color[i] = curr_color == 1 ? 2 : 1;
            if(dfs(g, color, color[i], i) == false)
                return false;
        }
        if(color[i] == curr_color) return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n = edges.size(), m = edges[0].size();
    vector<int> color(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(edges[i][j])
                g[i].push_back(j);
        }
    }
    for(int i = 0; i < n; ++i) {
        if(color[i] == 0) {
            color[i] = 1;
            if(dfs(g, color, color[i], i) == false)
                return false;
        }
        
    }
    return true;
}
