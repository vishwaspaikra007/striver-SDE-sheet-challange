// striver SDE sheet challange sudoku
// author Vishwas Paikra
bool isSafe(int matrix[9][9], int i, int j, int k) {
    for(int x = 0; x < 9; ++x) {
        if(matrix[i][x] == k ||
           matrix[x][j] == k ||
           matrix[3*(i/3) + (x/3)][3*(j/3) + x%3] == k)
            return false;
    } 
    return true;
}
bool BT(int matrix[9][9]) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(matrix[i][j]) continue;
            for(int k = 1; k <= 9; ++k) {
                if(isSafe(matrix, i, j, k)) {
                    matrix[i][j] = k;
                    if(BT(matrix) == true)
                        return true;
                    matrix[i][j] = 0;
                }
            }
            return false;
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    return BT(matrix);
}
