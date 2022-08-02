// striver SDE sheet challange Strongly Connected Components (Tarjan’s Algorithm)maximum-subarray-sum
// author Vishwas Paikra
#include<bits/stdc++.h>
void rdfs(int curr_node, vector<bool> &visited, vector<vector<int>> &rg, vector<int> &temp) {
    temp.push_back(curr_node);
    for(int node : rg[curr_node]) {
        if(!visited[node]) {
            visited[node] = true;
            rdfs(node, visited, rg, temp);
        }
    }
}
void dfs(int curr_node, vector<bool> &visited, vector<vector<int>> &g, stack<int> &stk) {
    for(int node : g[curr_node]) {
        if(!visited[node]) {
            visited[node] = true;
            dfs(node, visited, g, stk);
        }
    }
    stk.push(curr_node);
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> g(n), rg(n);
    vector<bool> visited(n);
    stack<int> stk;
    vector<vector<int>> ans;
    for(auto vec : edges) {
        g[vec[0]].push_back(vec[1]);
    }
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, visited, g, stk);
        }
    }
    for(int i = 0; i < n; ++i) {
        visited[i] = false;
        for(int j : g[i])
            rg[j].push_back(i);
    }
    while(!stk.empty()) {
        int i = stk.top();
        stk.pop();
        if(!visited[i]) {
            visited[i] = true;
            vector<int> temp;
            rdfs(i, visited, rg, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
