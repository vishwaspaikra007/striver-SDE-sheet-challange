// striver SDE sheet challange Detect Cycle In A Directed Graph
// author Vishwas Paikra
bool dfs(unordered_map<int, vector<int>> &g, unordered_map<int, bool> &chk, int idx, int head) {
    for(int node : g[idx]) {
        if(!chk[node]) {
            chk[node] = true;
            if(dfs(g, chk, node, head))
                return true;
        } else if(node == head) return true;
    }
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> chk;
    for(auto nodes : edges)
        g[nodes.first].push_back(nodes.second);
    
    for(int i = 1; i <= n; ++i) {
        if(!chk[i]) {
            chk[i] = true;
            if(dfs(g, chk, i, i))
                return true;
            
        }
    }
    return false;
}
