// striver SDE sheet challange rotate-matrix
// author Vishwas Paikra
#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int i = 0, prev = mat[0][0];
    int u=0,v=m-1,x=0,y=n-1;
    while(x<y && u<v) {
        // left to right
        for(int j=u;j<=v;++j) {
            swap(mat[x][j], prev);
        }
        // top to bottom
        for(int j=x+1;j<=y;++j) {
            swap(mat[j][v], prev);
        }
        // right to left
        for(int j=--v;j>=u;--j) {
            swap(mat[y][j], prev);
        }
        // bottom to top
        for(int j=--y;j>=x;--j) {
            swap(mat[j][u], prev);
        }
        ++x; ++u;
        prev = mat[x][u];
    }
}
