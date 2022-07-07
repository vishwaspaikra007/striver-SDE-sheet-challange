// striver SDE sheet challange Rotting Oranges
// author Vishwas Paikra
#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int, int>> stk;
    int tot = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] != 0) ++tot;
            if(grid[i][j] == 2) stk.emplace(i, j);
        }
    }
    int len = stk.size();
    int cnt = 0;
    int days = 0;
    int dir[] = {-1, 0, 1, 0, -1};
    while(len) {
        cnt += len;
        while(len--) {
            int x = stk.front().first;
            int y = stk.front().second;
            stk.pop();
            for(int i = 1; i < 5; ++i) {
                int u = x + dir[i-1];
                int v = y + dir[i];
                if(u >= 0 && v >= 0 && u < n && v < m && grid[u][v] == 1) {
                    grid[u][v] = 2;
                    stk.emplace(u,v);
                }
            }
        }
        len = stk.size();
        if(len) ++days;
    }
    return tot == cnt ? days : -1;
}
