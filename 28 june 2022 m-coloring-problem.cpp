// striver SDE sheet challange m-coloring-problem
// author Vishwas Paikra
bool isValid(int row, int color, vector<vector<int>> &mat, vector<int> &col) {
    for(int j = 0; j < mat.size(); ++j) {
        if(mat[row][j] && col[j] == color)
            return false;  
    }
    return true;
}
bool BT(vector<vector<int>> &mat, int m, int row, vector<int> &col) {
    if(row == mat.size()) return true;
    for(int color = 1; color <= m; ++color) {
        if(isValid(row, color, mat, col)) {
            col[row] = color;
            if(BT(mat, m, row + 1, col)) return true;
            col[row] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    vector<int> col(mat.size(), 0);    
    return BT(mat, m, 0, col) ? "YES" : "NO";
}   
