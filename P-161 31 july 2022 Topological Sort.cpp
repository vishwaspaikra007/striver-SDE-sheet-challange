// striver SDE sheet challange Topological Sort
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
    queue<int> stk;
    vector<vector<int>> g(V);
    vector<int> ans;
    vector<int> indegree(V);
    for(auto &vec : edges) {
        ++indegree[vec[1]];
        g[vec[0]].push_back(vec[1]);
    }
    for(int i = 0; i < V; ++i)
        if(indegree[i] == 0)
            stk.push(i);
    while(!stk.empty()) {
        int x = stk.front();
        stk.pop();
        ans.push_back(x);
        for(int i : g[x]) {
            --indegree[i];
            if(indegree[i] == 0) {
                stk.push(i);
            }
        }
    }
    return ans;
}
