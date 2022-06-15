// striver SDE sheet Challange set-matrix-zeros
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    bool isCol = false;
    for(int i=0;i<n;++i) {
        if(!matrix[i][0]) isCol = true;
        for(int j=1;j<m;++j) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i=1;i<n;++i) {
        for(int j=1;j<m;++j)
            if(!matrix[i][0] || !matrix[0][j])
                matrix[i][j] = 0;
    }
    if(!matrix[0][0]) {
      for(int i=0;i<m;++i) {
          matrix[0][i] = 0; 
      }  
    }
    if(isCol) {
      for(int i=0;i<n;++i) {
          matrix[i][0] = 0; 
      }  
    }
}
