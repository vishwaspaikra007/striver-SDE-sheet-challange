// striver SDE sheet challange BFS in Graph
// author Vishwas Paikra
#include<bits/stdc++.h>
void bfs(unordered_map<int, set<int>> &g, vector<bool> &chk, vector<int> &ans, int node) {
    queue<int> stk;
    stk.push(node);
    chk[node] = true;
    ans.push_back(node);
    while(!stk.empty()) {
        int x = stk.front();
        stk.pop();
        for(int i : g[x]) {
            if(!chk[i]) {
                stk.push(i);
                chk[i] = true;
                ans.push_back(i);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> g;
    vector<bool> chk(vertex);
    vector<int> ans;
    for(auto p : edges) {
        g[p.second].insert(p.first);
        g[p.first].insert(p.second);
    }
    for(int i = 0; i < vertex; ++i)
        if(!chk[i])
            bfs(g, chk, ans, i);
    
    return ans;
}
