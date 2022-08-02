// striver SDE sheet challange Dijkstra's shortest path
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    priority_queue<pair<int, int>,vector<pair<int,int> >,greater<pair<int,int>>> stk;
    vector<vector<int>> g(vertices);
    vector<vector<int>> weights(vertices, vector<int>(vertices, INT_MAX));
    vector<int> ans(vertices, INT_MAX);
    ans[0] = 0;
    
    for(auto &v : vec) {
        g[v[0]].push_back(v[1]);
        g[v[1]].push_back(v[0]);
        weights[v[0]][v[1]] = min(weights[v[0]][v[1]], v[2]);
        weights[v[1]][v[0]] = min(weights[v[1]][v[0]], v[2]);
    }
    stk.emplace(0, 0);
    while(!stk.empty()) {
        int node = stk.top().second;
        int max_weight = stk.top().first;
        stk.pop();
        for(int neighbour : g[node]) {
            int new_max_weight = max_weight + weights[node][neighbour];
            if(ans[neighbour] > new_max_weight) {
                ans[neighbour] = new_max_weight;
                stk.emplace(new_max_weight, neighbour);
            }
        }
    }
    return ans;
}
