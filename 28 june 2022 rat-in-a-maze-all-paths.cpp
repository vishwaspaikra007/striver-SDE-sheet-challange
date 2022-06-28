// striver SDE sheet challange rat-in-a-maze-all-paths
// author Vishwas Paikra
void BT(vector<vector<int>> &maze, vector<vector<int>> &ans, vector<int> &temp, int row, int col, int n) {
    if(row == n-1 && col == n-1) {
        ans.push_back(temp);
        return;
    }
    int x[] = {-1, 0, 1, 0, -1};
    for(int i = 1; i < 5; ++i) {
        int u = row + x[i-1];
        int v = col + x[i];
        if(u>-1 && v>-1 && u<n && v<n && maze[u][v] == 1) {
            maze[u][v] = 2;
            temp[u*n + v] = 1;
            BT(maze, ans, temp, u, v, n);
            temp[u*n + v] = 0;
            maze[u][v] = 1;
        }
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;
    if(!maze[0][0] || !maze[n-1][n-1]) return ans;
    vector<int> temp(n*n, 0);
    maze[0][0] = 2;
    temp[0] = 1;
    BT(maze, ans, temp, 0, 0, n);
    return ans;
}
