// striver SDE sheet challange search-in-a-2d-matrix
// author Vishwas Paikra
#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int i = 0, mid, j = m*n - 1;
    while(i<=j) {
        mid = i+(j-i)/2;
        int x = mid/n;
        int y = mid%n;
        if(mat[x][y] == target) return true;
        else if(mat[x][y] < target) i = mid + 1;
        else j = mid - 1;
    }
    return false;
}
