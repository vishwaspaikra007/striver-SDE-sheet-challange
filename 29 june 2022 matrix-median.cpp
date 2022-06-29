// striver SDE sheet challange matrix-median
// author Vishwas Paikra
#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int x = m*n;
    vector<int> mat;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            mat.push_back(matrix[i][j]);
    sort(mat.begin(), mat.end());
    return mat[x/2];
}

// another method without sort

// striver SDE sheet challange matrix-median
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> merge(vector<int> &list, vector<vector<int>> &matrix, int idx) {
    vector<int> newList;
    int i = 0, j = 0;
    while(i < matrix[0].size() && j < list.size()) {
        if(matrix[idx][i] < list[j]) newList.push_back(matrix[idx][i++]);
        else newList.push_back(list[j++]);
    }
    while(i < matrix[0].size()) 
        newList.push_back(matrix[idx][i++]);
    
    while(j < list.size())
        newList.push_back(list[j++]);
    
    return newList;
}
int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> mat;
    for(int i = 0; i < n; ++i) {
        mat = merge(mat, matrix, i);
    }
    return mat[(m*n)/2];
}
