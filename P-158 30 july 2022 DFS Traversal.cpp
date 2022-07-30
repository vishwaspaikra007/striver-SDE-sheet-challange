// striver SDE sheet challange DFS Traversal
// author Vishwas Paikra
void dfs(vector<vector<int>> &g, vector<bool> &chk, vector<int> &ans, int idx) {
    for(int i : g[idx]) {
        if(!chk[i]) {
            ans.push_back(i);
            chk[i] = true;
            dfs(g, chk, ans, i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> g(V);
    vector<bool> chk(V);
    vector<vector<int>> ans;
    
    for(auto &vec : edges) {
        g[vec[0]].push_back(vec[1]);
        g[vec[1]].push_back(vec[0]);
    }
    for(int i = 0; i < V; ++i) {
        if(!chk[i]) {
            vector<int> temp;
            chk[i] = true;
            temp.push_back(i);
            dfs(g, chk, temp, i);
            ans.push_back(temp);
        }
    }
    return ans;
}
