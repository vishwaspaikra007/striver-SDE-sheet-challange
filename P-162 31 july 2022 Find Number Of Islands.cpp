// striver SDE sheet challange Find Number Of Islands
// author Vishwas Paikra
void dfs(int i, int j, int n, int m, int** arr) {
    int arr1[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int arr2[] = {-1, 1, 1, 1, 0, -1, -1, -1};
    for(int k = 0; k < 8; ++k) {
        int x = i + arr1[k];
        int y = j + arr2[k];
        if(x>=0 && y>=0 && x<n && y<m && arr[x][y] == 1) {
            arr[x][y] = 2;
            dfs(x, y, n, m, arr);
        }
    }
}
int getTotalIslands(int** arr, int n, int m)
{
   int cnt = 0;
   for(int i = 0; i < n; ++i) {
       for(int j = 0; j < m; ++j) {
           if(arr[i][j] == 1) {
               ++cnt;
               arr[i][j] == 2;
               dfs(i, j, n, m, arr);
           }
       }
   }
   return cnt;
}
