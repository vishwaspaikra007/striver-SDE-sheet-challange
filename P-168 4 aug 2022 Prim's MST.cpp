// striver SDE sheet challange Prim's MST
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int, int>>> g1(n+1);
    vector<bool> visited(n+1); 
    vector<pair<pair<int, int>, int>> ans;
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > p;

    for(auto &x : g) {
        g1[x.first.first].emplace_back(x.second, x.first.second);
        g1[x.first.second].emplace_back(x.second, x.first.first);
    }
    int parent[n+1];
    vector<int> weight(n+1, INT_MAX);
    p.emplace(0, 1);
    while(!p.empty()) {
        int node = p.top().second;
        p.pop();
        visited[node] = true;
        for(auto &x : g1[node]) {
            if(!visited[x.second] && x.first < weight[x.second]) {
                p.emplace(x.first, x.second);
                parent[x.second] = node;
                weight[x.second] = x.first;
            }
        }   
    }
    for(int i = 2; i <= n; ++i) {
        ans.push_back(make_pair(make_pair(parent[i], i), weight[i]));
    }
    return ans;
}
