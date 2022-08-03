// striver SDE sheet challange Floyd Warshall
// author Vishwas Paikra
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    int maxi = 1000000000;
    vector<vector<int>> g(n+1, vector<int>(n+1, maxi));
    for(auto &vec : edges) {
        g[vec[0]][vec[1]] = vec[2];
    }
    
    for(int i = 1; i <= n; ++i) g[i][i] = 0;
    
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(g[i][k] != maxi && g[k][j] != maxi && g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    return g[src][dest];
}
